#include<cstdio>
#define MAX 100
bool AreElephantsHappy(int n, int c){
	int total_candies_req = 0;
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		total_candies_req+=temp;
	}
	return total_candies_req<=c ? true : false ;
}

int main(){
	int num_tests,n,c;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&n,&c);
		AreElephantsHappy(n,c) ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
