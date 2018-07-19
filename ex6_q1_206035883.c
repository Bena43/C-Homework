#include <stdio.h>



#define LSB_MASK 1

int main(){
	int numb,counter = 0;
	printf("Please enter an integer number: ");
	scanf("%d",&numb);
	while (numb>0){
		/*counts the number of bits. if numb equals to 1, counter increases by one
		  by dividing in 2 in every iteration we shorten the binary representation of numb in one digit.*/
		if (LSB_MASK & numb)
			counter +=1;
		numb/=2;
	}
	printf("The number of bits on: %d\n", counter);
	return 0;
}