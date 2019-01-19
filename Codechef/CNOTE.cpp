#include<cstdio>
#define MAX 100001

bool IsNoteBookAvailable(int pages_req, int k, int n, int *p, int *c){
	for(int i=0;i<n;i++){
		scanf("%d%d",&p[i],&c[i]);
	}
	for(int i=0;i<n;i++){
		if(pages_req <=p[i] && c[i]<=k)
			return true;
	}
	return false;
}

int main(){
	int num_tests, x,y,n,k,c[MAX],p[MAX] ;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d%d%d",&x,&y,&k,&n);
		IsNoteBookAvailable(x-y,k,n,p,c) ? printf("LuckyChef\n") : printf("UnluckyChef\n");
	}
	return 0;
}
