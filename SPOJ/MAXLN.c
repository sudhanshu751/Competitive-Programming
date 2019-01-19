#include <stdio.h>
 
double maxS(long long int R){
	return (16.0*R*R+1.0)/4.0 ;
}
 
int main(){
	int num_tests;
	long long int R;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
			scanf("%lld",&R);
			printf("Case %d: %0.2lf\n",i+1,maxS(R));
	}
	return 0;
}
