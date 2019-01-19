#include <stdio.h>
int numZeroes(int input);

int main(void){
	int num_tests,N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		printf("%d\n",numZeroes(N));
	}
	return 0;
}

int numZeroes(int input){
	int zeroes = 0;
	while(input){
		zeroes+= input/5;
		input/=5;
	}
	return zeroes;
}
