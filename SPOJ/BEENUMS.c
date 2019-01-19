#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int isBeehiveNumber(int N){
	int x,y;
	if((N-1)%6 != 0)
		return 0;
	x = (N-1)/6;
	y = (int)sqrt((double)1+8*x);
	if(y*y != 1+8*x)
		return 0;
	return y%2==1 ? 1 : 0;
		
}

int main(void){
	int N;
	while(scanf("%d",&N) && N!=-1){
		isBeehiveNumber(N) ? printf("Y\n") : printf("N\n") ;
	}
	return 0;
}
