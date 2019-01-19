#include<cstdio>
int MinIndex(int n){
	int next_num, smallest_num, min_position;
	scanf("%d",&smallest_num);
	min_position=1;
	for(int i=2;i<=n;i++){
		scanf("%d",&next_num);
		if(next_num < smallest_num){
			smallest_num=next_num;
			min_position = i;
		}
	}
	return min_position;
}

int main(){
	int num_tests,n;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&n);
		printf("%d\n",MinIndex(n));
	}
	return 0;
}
