#include <stdio.h>

int main(void){
	unsigned long long int num_tests,k ;
	scanf("%llu",&num_tests);
	for(unsigned long long int   i=0;i<num_tests;i++){
		scanf("%llu",&k);
		printf("%llu\n",192 + (k-1)*250);
	}
	return 0;
}
