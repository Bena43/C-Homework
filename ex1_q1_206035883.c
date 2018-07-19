#include <stdio.h>

int main1()
{
	int a, b, c;
	/* the users gives us an equation, a+b=c, and the program checks if the equation is mathematicly true.*/
	printf("Please enter an a+b=c equation:\n");
	scanf("%d+%d=%d",&a,&b,&c);
	if(a+b==c)
		printf("Equation is true.");
	else
		printf("Equation is false.");
	return 0;
}