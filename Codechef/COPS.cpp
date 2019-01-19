#include<cstdio>
#define MAX 100

int numSafeHouses(bool *A, int m, int x, int y){
	int cophouse,lowerlimit, upperlimit, max_visit_houses= x*y;
	int num_safe_houses=0;
	for(int i=0;i<m;i++){
		scanf("%d",&cophouse);
		--cophouse;
		lowerlimit=cophouse-max_visit_houses;
		upperlimit=cophouse+max_visit_houses;
		for(int j=cophouse;j>=0 && j>=lowerlimit;j--)
			A[j]=false;
		for(int j=cophouse;j<=99 && j<=upperlimit;j++)
			A[j]=false;
	}
	for(int i=0;i<MAX;i++)
		if(A[i])num_safe_houses++;

	return num_safe_houses;
}

int main(){
	int num_tests,m,x,y;
	bool A[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d%d",&m,&x,&y);
		for(int j=0;j<MAX;j++)
			A[j]=true;
		printf("%d\n",numSafeHouses(A,m,x,y));
	}
	return 0;

}
