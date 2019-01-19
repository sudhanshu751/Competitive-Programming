#include<cstdio>
void PrintChamberContents(int A,int n,int k){
	if(A==0 || n==0){
		for(int i=0;i<k;i++)
			printf("%d ",0);
		return;
	}

	int divisor=n+1,dividend;
	for(int i=0;i<k;i++){
		dividend=A;
		for(int j=1;j<=i;j++)
			dividend/=divisor;
		printf("%d ",dividend%divisor);
	}
}

int main(){
	int A,n,k;
	scanf("%d%d%d",&A,&n,&k);
	PrintChamberContents(A,n,k);
	return 0;
}
