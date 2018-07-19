#include <stdio.h>


#define LSB_MASK 1


int main(){
	int numb,counter = 0;
	printf("Please enter an integer number: ");
	scanf("%d",&numb);
	while (numb>0){
		if (LSB_MASK & numb)
			//counts the number of ones in the binary representation of numb
			counter +=1;
		numb/=2;
	}
	if (counter==1){
	//if only one time we have a one, its a power of 2
	printf("The number is a power of 2: True\n");
	return 0;}
	printf("The number is a power of 2: False\n");
	return 0;
}