#include<cstdio>
#include<climits>
#define MAX 700
long long MaxScore(int (*A)[MAX], int N){
	long long int score=0;
	int current_max,last_max=INT_MAX ;
	for(int i=N-1;i>=0;i--){
		current_max=INT_MIN ;
		for(int j=0;j<N;j++){
			if(A[i][j]>current_max && A[i][j]<last_max)
				current_max=A[i][j];
		}
		if(current_max==INT_MIN)
			return -1;
		else {
			score+=current_max;
			last_max=current_max;
		}
	}
	return score ;
}

int main(){
	int num_tests,N,A[MAX][MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				scanf("%d",(*(A+j)+k));
		printf("%lld\n",MaxScore(A,N));
	}
	return 0;
}
