#include <stdio.h>

int main(void){
	unsigned long long int input;
	scanf("%llu",&input);
	if(input ==0){
		printf("TAK\n");
		return 0;
	}
	(input & (input-1)) ? printf("NIE\n") : printf("TAK\n");
	return 0;
}
