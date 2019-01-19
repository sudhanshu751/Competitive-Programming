#include <stdio.h>

int nextServe(int p1, int p2, int k){
	long long int total  = p1+p2;
	return (total/k) & 1;
}

int main(){
	int num_tests, p1,p2,k;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d%d",&p1,&p2,&k);
		if(nextServe(p1,p2,k))
			printf("COOK\n");
		else 
			printf("CHEF\n");
	}
	return 0;
}
