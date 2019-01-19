#include<cstdio>
int main(){
	int numb_tests;
	long long int u,v,rank ;
	scanf("%d",&numb_tests);
	for(register int i=0;i<numb_tests;i++){
		scanf("%lld%lld",&u,&v);
		rank = ((u+v)*(u+v+1))/2 + (u+1);
		printf("%lld\n",rank);
	}
	return 0;
}
