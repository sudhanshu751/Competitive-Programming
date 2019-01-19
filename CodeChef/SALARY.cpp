#include <cstdio>
#include<algorithm>
#define MAX 100

long long int MinStepsToEqual(int *salary, int n){
	if(n<=1)
		return 0;
	long long int steps=0;
	std::sort(salary,salary+n);
	for(int i=1;i<n;i++)
		steps+=salary[i]-salary[0];
	return steps;
}

int main(){
	int num_tests,n,salary[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&n);
		for(int j=0;j<n;j++)
			scanf("%d", salary+j);
		printf("%lld\n",MinStepsToEqual(salary,n));
	}
	return 0;
}
