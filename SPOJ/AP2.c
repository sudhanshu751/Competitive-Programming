#include <stdio.h>

void printAP(long long int a3,long long int an_3,long long int sum){
	long long int n = (2*sum)/(a3+an_3);
	long long int d = (an_3-a3)/(n-5);
	long long int a = a3 - 2*d;
	printf("%lld\n",n);
	for(long long int i=1;i<=n;i++)
		printf("%lld ",a+(i-1)*d);
	printf("\n");
}

int main(void){
	int num_tests;
	long long int a3,an_3,sum;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%lld%lld%lld",&a3,&an_3,&sum);
		printAP(a3,an_3,sum);
	}
	return 0;
}
