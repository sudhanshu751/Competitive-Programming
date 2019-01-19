#include <stdio.h>

int reversedNumber(int input){
	if(input >= 0 && input < 10)
		return input;
	int output = 0,digit=0;
	while(input){
		digit = input%10;
		output = (output*10+digit);
		input /=10;
	}
	return output;
}

int main(void){
	int num_tests,A,B;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&A,&B);
		printf("%d\n",reversedNumber(reversedNumber(A)+reversedNumber(B))) ;
	}
	return 0;
}
