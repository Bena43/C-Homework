#include <stdio.h>

int sumDivisors (int numb)
	/* this function calculates the sum of all of "numb"'s divisors (not including himself)*/
{int result = 0;
int i = 0;
	for (i=1;i<numb;i++)
	{if (numb % i == 0)
     	result += i;
	}
	return result;
}
int isPerfectNumber(int numb)
	/* this function checks if a number "numb" is perfect"*/
{return (sumDivisors(numb) == numb);}

int areAmicableNumbers(int numb, int numb2)
	/* this function checks if "numb" and "numb2" are amicable numbers*/
{	return ((sumDivisors(numb) == numb2) && (sumDivisors(numb2) == numb));}

int main()
{ int First=0;
int Second=0;
while (First<1 || Second<1)
{
printf("Please enter two positive integers.\n");
scanf("%d %d",&First,&Second);}

	if (isPerfectNumber(First) == 1)
		printf ("The number %d is a perfect number.\n",First);
	else
		printf ("The number %d is not a perfect number.\n",First);
	if (isPerfectNumber(Second) == 1)
		printf ("The number %d is a perfect number.\n",Second);
	else
		printf ("The number %d is not a perfect number.\n",Second);
	if (areAmicableNumbers(First,Second))
		printf("The number %d and %d are amicable numbers.",First,Second);
	else
		printf("The numbers %d and %d are not amicable numbers.\n",First,Second);
	
return 0;
}
