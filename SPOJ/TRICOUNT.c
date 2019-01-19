#include <stdio.h>

long long int numTriangles(long long int N){
	long long int upper,lower,x;
	upper  = (N*(N+1)*(N+2))/6;
	N = N-1;
	if(N%2){
		x= (N+1)/2;
		lower = (x*(x+1)*(4*x-1))/6;
	
	}
	else{
		x = N/2;
		lower= (x*(x+1)*(4*x+5))/6;
	}
	return upper+lower;
}

int main(void){
	int num_tests;
	long long int N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%lld",&N);
		printf("%lld\n",numTriangles(N));
	}
	return 0;
}
