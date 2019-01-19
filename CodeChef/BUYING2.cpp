#include<cstdio>
int NumberOfSweets(int n, int x);

int main(){
	int num_tests, n, x;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&n,&x);
		printf("%d\n",NumberOfSweets(n,x));
	}
	return 0;
}

int NumberOfSweets(int n, int x){
	int min=0xfffffff,temp,sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		sum+=temp;
		if(temp<min)
			min=temp;
	}
	if(min<=(sum%x))
		return -1;
	else 
		return sum/x;
}
