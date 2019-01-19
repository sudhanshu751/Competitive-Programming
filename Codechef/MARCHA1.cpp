#include<cstdio>
#define MAX1 21
#define MAX2 1001

bool SubsetSum(bool (*DP)[MAX2],int *notes, int n, int m){
	if(m==0 && n>=0)
		return true;
	else if(n<1 && m!=0)
		return false;

	for(int i=0;i<=n;i++)
		DP[i][0]=true;
	for(int j=1;j<=m;j++)
		DP[0][j]=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j<notes[i-1])
				DP[i][j]=DP[i-1][j];
			else
				DP[i][j]=DP[i-1][j-notes[i-1]] || DP[i-1][j];
		}
	}
	return DP[n][m];
}

int main(){
	int num_tests,n,m,notes[MAX1];
	bool DP[MAX1][MAX2];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&n,&m);
		for(int j=0;j<n;j++)
			scanf("%d",notes+j);
		SubsetSum(DP,notes,n,m) ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
