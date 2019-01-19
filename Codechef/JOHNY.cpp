#include<cstdio>
#define MAX 100
int PositionUncleJohnny(int *A, int n, int k){
	int position=0;

	int temp = A[0];
	A[0]=A[k-1];
	A[k-1]=temp;

	for(int i=1;i<n;i++)
		if(A[i]<A[0])
			position++;
	return position+1;
}

int main(){
	int num_tests, n, k, song_length[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&n);
		for(int j=0;j<n;j++)
			scanf("%d",song_length+j);
		scanf("%d",&k);
		printf("%d\n",PositionUncleJohnny(song_length,n,k));
	}
	return 0;
}
