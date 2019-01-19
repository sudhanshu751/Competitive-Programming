#include <cstdio>
#include <algorithm>
#define MAX 1001

int sumHotness(int *men, int *women, int N){
	int sum = 0;
	std::sort(men,men+N);
	std::sort(women,women+N);
	for(int i=0;i<N;i++)
		sum+=men[i]*women[i];
	return sum;
}

int main(){
	int num_tests, men[MAX],women[MAX],N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		for(int j=0;j<N;j++)
			scanf("%d",men+j);
		for(int j=0;j<N;j++)
			scanf("%d",women+j);
		printf("%d\n",sumHotness(men,women,N));
	}
	return 0;
}
