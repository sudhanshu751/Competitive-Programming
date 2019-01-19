#include <stdio.h>
#include <string.h>
#define MAX 100 

int maxStones(int (*stones)[MAX],int (*dp)[MAX],int h, int w);

int main(void){
	int num_tests,h,w,stones[MAX][MAX],dp[MAX][MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&h,&w);
		memset(dp,0,sizeof(dp));
		for(int i=h-1;i>=0;i--){
			for(int j=0;j<w;j++)
				scanf("%d",&stones[i][j]);
		}
		printf("%d\n",maxStones(stones,dp,h,w));
	}
	return 0;
}

int maxStones(int (*stones)[MAX],int (*dp)[MAX],int h, int w){
	for(int j=0;j<w;j++)
		dp[0][j] = stones[0][j] ;
	int max_so_far;
	for(int i=1;i<h;i++){
		for(int j=0;j<w;j++){
			max_so_far= dp[i-1][j];
			if(j-1>=0)
				max_so_far = dp[i-1][j-1] >= max_so_far ? dp[i-1][j-1] : max_so_far ;
			if(j+1< w)
				max_so_far = dp[i-1][j+1] >= max_so_far ? dp[i-1][j+1] : max_so_far ;
			dp[i][j] = stones[i][j] + max_so_far ;
		}
	}
	max_so_far =0;
	for(int j=0;j<w;j++)
		max_so_far = dp[h-1][j] >= max_so_far ? dp[h-1][j] : max_so_far ;
	return max_so_far ;
}
