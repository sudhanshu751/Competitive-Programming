#include <stdio.h>

int main(void){
	unsigned long long int num_tests,candy,N,total=0;
	scanf("%llu",&num_tests);
	for(unsigned long long int i=0;i<num_tests;i++){
		scanf("%llu",&N);
		total=0;
		for(unsigned long long j=0;j<N;j++){
			scanf("%llu",&candy);
			total = (total%N + candy%N)%N ;
		}
		total ? printf("NO\n") : printf("YES\n") ;
	}
	return 0;
}
