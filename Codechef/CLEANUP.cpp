#include<cstdio>
#include<algorithm>
#define MAX 1000

void AssignJobs(int n, int *completedjobs, int m){
	if(n==0 || n==m){
		printf("\n\n");
		return ;
	}
	if(m!=0)
		std::sort(completedjobs, completedjobs+m);
	bool chefturn=true;
	for(int i=1,j=0;i<=n;i++){
		if(j<m && i==completedjobs[j])
			j++;
		else if(chefturn){
			printf("%d ",i);
			chefturn=false;
		}
		else
			chefturn=true;
	}
	printf("\n");
	chefturn=true;
	for(int i=1,j=0;i<=n;i++){
		if(j<m && i==completedjobs[j])
			j++;
		else if(!chefturn){
			printf("%d ",i);
			chefturn=true;
		}
		else
			chefturn=false;
	}
	printf("\n");
}
int main(){
	int num_tests,n,m,completedjobs[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&n,&m);
		for(int j=0;j<m;j++)
			scanf("%d",(completedjobs+j));
		AssignJobs(n,completedjobs,m);
	}
	return 0;
}
