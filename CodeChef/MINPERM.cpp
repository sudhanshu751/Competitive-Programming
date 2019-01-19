#include<cstdio>

void PrintGoodPermutation(int n){
	if(n<2)
		return;
	if(n%2==0){
		for(int i=1;i<=n-1;i+=2){
			printf("%d %d",i+1,i);
			if(i!=n-1)
				printf(" ");
		}
	}
	else{
		for(int i=1;i<=n-4;i+=2)
			printf("%d %d ",i+1,i);
		printf("%d %d %d",n-1,n,n-2);
	}	
	printf("\n");
}

int main(){
	int num_tests,n;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&n);
		PrintGoodPermutation(n);
	}
	return 0;
}
