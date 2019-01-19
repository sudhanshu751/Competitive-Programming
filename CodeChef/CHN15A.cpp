#include<cstdio>

int NumWolverineMinions(int n, int k){
	int temp;
	int count=0;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if((temp+k)%7==0)
			count++;
	}
	return count ;
}

int main(){
	int num_tests,n,k;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&n,&k);
		printf("%d\n",NumWolverineMinions(n,k));
	}
	return 0;
}
