#include <stdio.h>

int main()
{/*user gives his "Bruto" salary, and we calculate how much taxes he needs to pay, using the tax-table given. salary <= 0 is not valid.
 f.e:
 salary = 6275.3 --> tax = 669.749, net = salary - tax = 5605.601*/
	float tax, final, salary;
	printf("Please enter monthly salary:\n");
	scanf("%f", &salary);

	if(salary == 0 || salary < 0 )
		printf("The salary is not valid!\n");
	if(salary>0 && salary <=5220)
	{
		tax = salary/10;
		final = salary - tax;
		printf("Tax: %0.3f NIS\n",tax);
		printf("Net income: %0.3f NIS\n",final);
	}
	if(salary>5220 && salary <=8920)
	{
		tax=(salary-5220)*0.14 + 522;
		final = salary - tax;
		printf("Tax: %0.3f NIS\n",tax);
		printf("Net income: %0.3f NIS\n",final);
	}
	
	if(salary>8920 && salary <=13860)
	{
		tax =(salary-8920)*0.21+1040;
		final = salary - tax;
		printf("Tax: %0.3f NIS\n",tax);
		printf("Net income: %0.3f NIS\n",final);
	}
	if(salary>13860 && salary <=19800)
	{
		tax =(salary-13860)*0.31+2077;
		final = salary - tax;
		printf("Tax: %0.3f NIS\n",tax);
		printf("Net income: %0.3f NIS\n",final);
	}
	if(salary>19800 && salary<=41410)
	{
		tax = (salary-19800)*0.34+3919;
		final = salary - tax;
		printf("Tax: %0.3f NIS\n",tax);
		printf("Net income: %0.3f NIS\n",final);
	}
	if(salary > 41410 && salary <= 66960)
	{
		tax =(salary-41410)*0.48+11266;
		final = salary - tax;
		printf("Tax: %0.3f NIS\n",tax);
		printf("Net income: %0.3f NIS\n",final);
	}
	if(salary>66960)
	{
		tax = 23530 + (salary-66960)*0.5;
		final = salary - tax;
		printf("Tax: %0.3f NIS\n",tax);
		printf("Net income: %0.3f NIS\n",final);
	}
	return 0;
}