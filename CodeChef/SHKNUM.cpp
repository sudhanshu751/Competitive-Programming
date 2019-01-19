#include <cstdio>
#include <cmath>
#include <cstdlib>
#define MAXBITS 30

int minSteps(int N);

int main(){
	int num_tests, N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		printf("%d\n",minSteps(N));
	}
	return 0;
}

int minSteps(int N){
	unsigned int minsteps = 0xffffffff;
	unsigned int temp,difference;
	for(int i=0;i<=MAXBITS;i++){
		for(int j=0;j<=MAXBITS;j++){
			if(i==j)
				continue;
			temp = (01<<i) + (01<<j);
			difference = abs(temp-N);
			if(difference < minsteps)
				minsteps = difference;
		}
	}
	return minsteps;
}
