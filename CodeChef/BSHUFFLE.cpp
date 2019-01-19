#include <cstdio>

void printMinProbablePermutation(int N){
	if(N==1){
		printf("1\n");
		return ;
	}
	printf("%d ",N);
	for(int i=1;i<N;i++)
		printf("%d ",i);
	printf("\n");
}
void swap(int *x,int *y){
	int temp = *x;
	*x=*y;
	*y=temp;
}

void printMaxProbablePermutation(int N){
	if(N==1){
		printf("1\n");
		return ;
	}
	int array[18];
	for(int i=2;i<=N;i++){
		array[i-1]=i;
	}
	array[N]=1;
	if(N%2){
		int mid = N/2 +1;
		swap(&array[mid],&array[N]);

	}
	else
		swap(&array[N/2],&array[N]);
	for(int i=1;i<=N;i++)
		printf("%d ",array[i]);
	printf("\n");
}

int main(){
	int input;
	scanf("%d",&input);
	printMaxProbablePermutation(input);
	printMinProbablePermutation(input);
	return 0;
}
