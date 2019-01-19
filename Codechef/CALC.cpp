#include<cstdio>
long long int maxnumonscreen2(long long int n,long long int b);
int main(){
	int n,b,num_tests;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&n,&b);
		printf("%lld\n",maxnumonscreen2(n,b));
	}
	return 0;
}

long long int maxnumonscreen2(long long int n,long long int b){
	if(n==0 || b==0)
		return 0;	
	if(n<=b)
		return 0;
	long long int a, d, num_terms,result;
	a= 1+(n-1-b)*1 ; 
	d= (-2)*b;
	num_terms = ((n-1-b)/(2*b)) + 1 ;
	result = (num_terms*(2*a + (num_terms-1)*d)) / 2 ;
	return result;
}
