#include <stdio.h>
#define MAX 10001
#include <string.h>
long long int max(long long int x, long long int y){
	return x>=y ? x :y ;
}

long long int maxGoldCoins(long long int *coins,long long int *dp, int size){
	if(size < 2){
		return coins[size];
	}
	dp[1]=coins[1];
	for(int i=2;i<=size;i++)
		dp[i]= max(dp[i-1],coins[i]+dp[i-2]);
	return dp[size];
}

int main(void){
	long long int coins[MAX+1],dp[MAX+1];
	int num_tests,N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		memset(dp,0,sizeof(dp));
		coins[0]=0;
		for(int j=1;j<=N;j++)
			scanf("%lld",coins+j);
		printf("Case %d: %lld\n",i+1,maxGoldCoins(coins,dp,N));
	}
	return 0;
}
