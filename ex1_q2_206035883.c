#include <stdio.h>

int main()
{
	int num,a,b,c,d;
	/*a,b,c,d are num's digits. in this program we reverse the number. abcd --> dcba. f.e: 1234 --> 4321*/
	printf("Please enter a 4-digit integer:\n");
	scanf("%d",&num);
	if((num<1000) || (num>9999))
		printf("The number is not a 4-digit number!\n");
	else
		{d = num%10;
		c = (num/10)%10;
		b = (num/100)%10;
		a = (num/1000);
		printf("Reversed number: %d%d%d%d\n",d,c,b,a);
	}
	return 0;
}