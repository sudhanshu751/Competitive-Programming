#include<cstdio>
#include<algorithm>
#define MAXSIZE 100001
void findmedian(int n, int *A);
int main(){
	int num_tests, N, A[MAXSIZE], doublesize;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		doublesize = 2*N;
		for(register int j=1;j<=doublesize;j++)
			scanf("%d",(A+j));
		findmedian(doublesize, A);
		printf("\n");
	}
	return 0;
}
void findmedian(int n, int *A){
	int i,j,temp;
	std::sort(A+1, A+1+n);
	int N = n/2;
	printf("%d\n",A[(3*N+1)/2]);
	i=1;
	j=n-1;
	while(i!=j){
		temp=A[i];
		A[i]=A[j];
		A[j]=temp;
		i+=2;
		j-=2;
	}
	for(register int k=1;k<=n;k++)
		printf("%d ",A[k]);
}
