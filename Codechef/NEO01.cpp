#include<cstdio>
#define MAXSIZE 100000
long long int max_happiness(int n, int *A);
int main(){
	int numb_tests, n, A[MAXSIZE];
	scanf("%d",&numb_tests);
	for(int i=0;i<numb_tests;i++){
		scanf("%d",&n);
		for(register int j=0;j<n;j++)
			scanf("%d",(A+j));
		printf("%lld\n",max_happiness(n,A));
	}
	return 0;
}
long long int max_happiness(int n, int *A){
	long long int total_happiness=0,subsetsize=0,subsetsum=0;
	for(register int i=0;i<n;i++){
		if(subsetsum + *(A+i)>=0){
			subsetsize++;
			subsetsum += *(A+i);
		}
		else{
			if(subsetsize!=0){
				total_happiness += subsetsize *subsetsum;
				subsetsize = subsetsum =0;
			}
			total_happiness += *(A+i);
		}
	}

	if(subsetsize!=0)
		total_happiness += subsetsize * subsetsum;
	return total_happiness ;
}
