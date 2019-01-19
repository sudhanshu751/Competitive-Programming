#include <stdio.h>
#define MOD 1000007

long long int numCards(long long int N){
	if(N==0)
		return 0;
	long long int total_cards = 0;
	total_cards = (N*(N+1)%MOD + (((N-1)*N)/2)%MOD)%MOD ;
	return total_cards;
}

int main(void){
	int num_tests;
	long long int N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%lld",&N);
		printf("%lld\n",numCards(N));
	}
	return 0;
}
