#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LSB_MASK 1


char * stringfy(unsigned int w,int length,int original)
{/*while original is 1, returns the original binary string, for example, 13 -> 1101.
   while original is 0, returns the reversed binary string, for example, 13 -> 1011*/
   char *s;
   int i;
   int MSB_MASK = 1<<(length-1);
	if (NULL == (s = (char *) malloc(length+1) ))  
		return NULL;
	if (original ==0){
   for (i=length-1; i > -1; i--, w <<= 1) {
	//runs from last to first.
	s[i] = '0';
	if ( w & MSB_MASK )
		s[i] = '1';
   }}
	else{
		   for (i=0; i < length; i++, w <<= 1) {
	s[i] = '0';
	if ( w & MSB_MASK )
		s[i] = '1';
		   }}
   s[length] = '\0';
   return s; }

int main(){
	int numb,counter = 0,temp;
	char *opposite, *original; 
	printf("Please enter an integer number: ");
	scanf("%d",&numb);
	temp = numb;
	while (temp>0){
		//counts how much numbers are there in the binary number of numb.
		counter +=1;
		temp/=2;
	}
	opposite = stringfy(numb,counter,0);
	original = stringfy(numb,counter,1);
	printf("The original number: %s",original);
	printf("\nReversed bits number: %s\n", opposite);
	return 0;
}