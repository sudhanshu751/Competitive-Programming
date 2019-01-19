#include<cstdio>
#define MAX 100000

long long int Min_Moves(int *A, int n, int d);

int main(){
	short int num_tests;
	int A[MAX], n, d ;
	scanf("%hd",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&n,&d);
		printf("%lld\n",Min_Moves(A,n,d));
	}
	return 0;
}

long long int Min_Moves(int *A, int n, int d){
	long long int moves=0, sum=0,average=0;
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",A+i);
		sum+=A[i];
	}
	if(sum%n!=0)
		return -1;
	else 
		average = sum/n ;
	for(i=0;i<d;i++){
		for(j=i;j<n;j+=d){
			if((A[j]<average) && (j+d<n)){
				moves+= average - A[j];
				A[j+d] -= average - A[j];
				A[j]=average ;
			}
			else if((A[j]>average) && (j+d<n)){
				moves+=A[j]-average ;
				A[j+d]+=A[j]-average ;
				A[j]=average ;
			}
		}
	}
	
	for(i=0;i<n;i++)
		if(A[i]!=average)
			return -1;
	return moves;
}
