#include <stdio.h>
int numSquares(int N){
	return (N*(N+1)*(2*N+1))/6 ;
}

int main(void){
	int N;
	while(scanf("%d",&N) && N!=0){
		printf("%d\n",numSquares(N));
	}
	return 0;
}
