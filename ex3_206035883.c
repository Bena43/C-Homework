#include <stdio.h>
#include "test_data.h"
#include <string.h>

//Q1
double char_to_res(char op,double first,double second)
	{/*given 2 numbers and an operator returns the result of the equation if them*/
		switch (op)
		{
		case '+':
			return (first + second);
			break;
		case '-':
			return (first - second);
			break;
		case '*':
			return (first*second);
			break;
		case '/':
			return (first / second);
			break;
		default:
		printf("we're not supposed to get here");
		return -1;
		}

}

int char_to_num(char b)
{/*takes a char of a single digit, returns the same number as an integer*/
	switch (b)
	{
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	default:
		printf("we're not supposed to get here");
		return -1;
	}
}

void mathStringCalc(char mathString[])
{/*reciving an equation as a string, prints the result of the equation*/
int i=0, firstdigit = 0, k = 0, counter = 0;
char op = 'd';//operator
double result,num;
	for (;mathString[i] !='\0';i++)
	{/*running on each char of string*/
		if (mathString[i] == ' '){
			/*counting the spaces. the odded index ones are the ones who need to be take care of*/
			counter +=1;

		}
		if ((mathString[i] == ' ') && (counter % 2!=0))
			{num = 0;

				for (k=firstdigit; k!=i; k++)
					{
					num = num*10 + char_to_num(mathString[k]);

					}
				if (op == 'd'){
					/*if its the first number*/
					result = num;

				}
				else
				{
					/*calculates the new result, when given the operator, the last result, and the new number*/

				result = char_to_res(op,result,num);
				
				}

				op=mathString[i+1]; //new operator for next iteration
				firstdigit = i+3; // the index of the first digit of next number

			}
	}
	num = 0;
	for (k=firstdigit;k!=i;k++)//k==i-1 -> k<i
		/*calculate again for the last number (because there are no spaces after the last number)*/
	{
		num = num*10 + char_to_num(mathString[k]);
	}
	result = char_to_res(op,result,num);
	printf("%s = %.3lf\n",mathString ,result);

}

//Q2
void nPlacesDiff(char str1[], char str2[], int n)
{int i=0,counter = 0,len1,len2,new_len;
	// calculating the hamming distance of 2 strings
	len1 = strlen(str1);
	len2 = strlen(str2);

	if (len1>len2)
		{
		new_len=len1-len2;
		counter+= (len1-len2);
		for (i=0;i!=len2;i++)
		{
			if (str1[i] !=str2[i])
				counter+=1;
		}
	}
	else
		{
		new_len=len2-len1;
		counter+=new_len;
		for (i=0;i!=len1;i++)
		{
			if (str1[i] !=str2[i])
				counter+=1;
		}}
	
	if (n==counter)
		printf("True\n");
	else
		printf("False\n");
}

// Q3
int Length_maze(int n, int maze[][N],  int memory_maze[][N], int x, int y); // auxiliary function for void path.

void path(int n, int maze[][N])
{
	int i,j,save,memory_maze[N][N];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) 
			memory_maze[i][j] = 1-n;
		
	}
	save = Length_maze(n, maze, memory_maze, n-1, n-1);	
	if (save == -1)
		printf("No path found!\n");
	else
	printf("Shortest path length is: %d\n", save);
}

int Length_maze(int n, int maze[][N],  int memory_maze[][N], int x, int y)
{int save, less_length;
	if (n == 1)
	{// 1on1 struct
		if (maze[0][0]==1)
		return 1;
		else 
			return -1;
	}

	if (x + y == 1 && maze[0][0]==1)
	{/*if (x,y) = (0,1) or (1,0)*/
		memory_maze[x][y] = 2;
		return 2;
	}

	if (memory_maze[x][y] > -2)
	return memory_maze[x][y];

	less_length = 401;
	save = -2;

	maze[x][y] = 0; //marking the ones i've been at


	if (0 < x)
		{if (maze[x-1][y] == 1) 
			{
			//go left
			if(memory_maze[x-1][y] > -2)
				save = memory_maze[x-1][y];
			else
				save = Length_maze(n, maze, memory_maze, x-1, y);//calculate length to get to 0,0
				

		if (save > 0)
			{//if save != -1 and less_length > save, then less_length = save
				if (less_length > save)
				less_length = save;
			}


	}}

	save = -2;

	if(x < n - 1)
	{
		if (maze[x+1][y] == 1)
		{
			// go right
			if (memory_maze[x+1][y] > -2)
			save = memory_maze[x+1][y];
			else
				save = Length_maze(n, maze, memory_maze, x+1, y);//calculate length to get to 0,0
			

			if (save > 0)
			{
				//if save != -1 and less_length > save, then less_length = save
				if (less_length > save)
				less_length = save;
			}

	}}

	save = -2;

	if (y < n - 1)
	{
		if (maze[x][y+1] == 1) 
		{
		//go down
		if(memory_maze[x][y+1] > -2)
		save = memory_maze[x][y+1];
		else
			save = Length_maze(n, maze, memory_maze, x, y+1);//calculate length to get to 0,0
		

		if (save > 0) 
		{//if save != -1 and less_length > save, then less_length = save
			if(less_length > save)
			less_length = save;}

	}}

	save = -2;

	if (0 < y)
	{//go up
		if (maze[x][y-1] == 1)
		{
		if (memory_maze[x][y-1] > -2)
		save = memory_maze[x][y-1];
		else
			save = Length_maze(n, maze, memory_maze, x, y-1);//calculate length to get to 0,0
		

		if(save > 0)
		{//if save != -1 and less_length > save, then less_length = save
			if(less_length > save)
			less_length = save;
		}

	}}
	
	maze[x][y] = 1; //unmarking so i could get back to it next "iteration"


	if (less_length > 399)
	{
		memory_maze[x][y] += 1;
		return -1;
	}
	less_length++;//for current space
	if (less_length > 0)
	memory_maze[x][y] = less_length;
	else
		memory_maze[x][y] += 1;


	return less_length;
}
//
 //exercise 3
int main()
{
	int opt = 0, i;

	printf("Hello. Please choose a question by entering 1-3:\n");
	scanf("%d", &opt);

	while (opt < 1 || opt > 3) {
		printf("Invalid number was entered. Please choose again 1-3:\n");
		scanf("%d", &opt);
	}

	switch (opt) {
		case 1:
			mathStringCalc(mathString1);
			mathStringCalc(mathString2);
			mathStringCalc(mathString3);
			mathStringCalc(mathString4);
			break;
		case 2:
			for (i = 0; i < 6; i++) {
				printf("(\"%s\", \"%s\", %d) -> ",
				       str_q2[i][0], str_q2[i][1], n_q2[i]);
				nPlacesDiff(str_q2[i][0], str_q2[i][1], n_q2[i]);
			}
			break;
		case 3:
			path(N, maze1);
			path(N, maze2);
			path(N, maze3);
			break;
			
		default:
			printf("We should not get here!\n");
	}
	return 0;
}
