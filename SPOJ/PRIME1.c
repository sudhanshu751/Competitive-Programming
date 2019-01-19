#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n){
	if(n!=2 && n%2==0)
		return 0;
	else if(n==2)
		return 1;
	for(int i=3;i*i<=n;i+=2){
		if(n%i==0)
			return 0;
	}
	return 1;
}

void printPrimes(int m, int n){
	int counter =m;
	if(m<=2 && n>=2){
		printf("%d\n",2);
		counter=3;
	}
	counter = counter%2==0 ? counter+1 : counter ;
	for(;counter<=n;counter+=2){
		if(isPrime(counter))
			printf("%d\n",counter);
	}
	return;
}

int main(void){
	int num_tests,m,n;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&m,&n);
		printPrimes(m,n);
		printf("\n");
	}
	return 0;
}
