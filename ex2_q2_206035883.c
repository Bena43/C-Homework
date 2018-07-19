#include <stdio.h>

int digit_ind(int num, int index)
{/*gets the digit of num located in "index", for example (9342,2) --> 3 */
	int i = 0;
	for (i;i<index;i++)
		num = num/10;	
	return (num%10);
}

int isValidNumber(int numb)
{/*checks if numb is a valid number to use for Kaprekar's routine(in this question's condiotions)*/
	if (numb<1000 || numb > 9999)
		return 0;
	if (digit_ind(numb, 3) == digit_ind(numb, 2) || digit_ind(numb, 3) == digit_ind(numb, 1) || digit_ind(numb, 3) == digit_ind(numb, 0) || digit_ind(numb, 2) == digit_ind(numb, 1) || digit_ind(numb, 2) == digit_ind(numb, 0) || digit_ind(numb, 1) == digit_ind(numb, 0))
		return 0;
	return 1;
}

int countBigger(int digit, int big1, int big2, int big3)
{ /*checks how much numbers are bigger than digit from big1,2,3*/
	int result=0;
	if (digit<big1)
		result+=1;
	if (digit<big2)
		result+=1;
	if (digit<big3)
		result+=1;
	return result;
}
int computeNewLocation(int digit, int biggers)
{
	/* computes the "Location" of the number (units/tenths etc..) f.e: for input (4,1) returns 400*/
	if (biggers == 0)
		return digit*1000;
	if (biggers == 1)
		return digit*100;
	if (biggers == 2)
		return digit*10;
	if (biggers == 3)
		return digit*1;
}


int descendingOrder (int numb)
{/*orginaize number by descending order. a>b>c>d, dcab --> abcd. 4621 -->6421.
 new_hunderds is the new number we get, from the digit used to be in the hunderd's.
 for example, new_hunderds in the example above will be 6000*/
	int new_units,new_tenths,new_hunderds,new_tousands;
	int result;
	new_units = computeNewLocation(digit_ind(numb, 0),countBigger(digit_ind(numb, 0),digit_ind(numb, 1),digit_ind(numb, 2),digit_ind(numb, 3)));
	new_tenths = computeNewLocation(digit_ind(numb, 1),countBigger(digit_ind(numb, 1),digit_ind(numb, 0),digit_ind(numb, 2),digit_ind(numb, 3)));
	new_hunderds = computeNewLocation(digit_ind(numb, 2),countBigger(digit_ind(numb, 2),digit_ind(numb, 1),digit_ind(numb, 0),digit_ind(numb, 3)));
	new_tousands = computeNewLocation(digit_ind(numb, 3),countBigger(digit_ind(numb, 3),digit_ind(numb, 1),digit_ind(numb, 2),digit_ind(numb, 0)));
	result = new_units + new_tenths + new_hunderds + new_tousands;
	return result;
}

int reverseDigitsOrder (int numb)
{/* reverse a 4-digit number's order. f.e: abcd --> dcba*/
	return (digit_ind(numb, 3)+(digit_ind(numb, 2)*10)+(digit_ind(numb, 1)*100)+(digit_ind(numb, 0)*1000));

}

int main()
{int numb = -42;
while (isValidNumber(numb) == 0)
{/*loops until user gives a valid number as asked*/
	printf("Please enter a positive integer (1000-9999, with different digits)\n");
	scanf("%d",&numb);
}
while (1>0)
{int descending, ascending,result;
	descending = descendingOrder(numb);
	ascending = reverseDigitsOrder(descending);
	result = descending - ascending;
	printf("%d-%d=%d\n",descending,ascending,result);

	if (!isValidNumber(result))
		{printf("The difference is not a valid number!\n");
		break;
		}
	if (result == numb)
		break;
	numb = result;
}

}