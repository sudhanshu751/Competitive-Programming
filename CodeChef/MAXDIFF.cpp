#include<cstdio>
#include<cmath>
#include<cstdlib>
#define MAX 100

int random_partition(int *A, int start, int end){
	int i,pivot,key,temp,random_index ;
	random_index = rand()%(end-start+1) + start ;
	temp=A[end];
	A[end]=A[random_index];
	A[random_index]=temp;
	key=A[end];
	i=pivot=start ;
	for(;i<end;i++){
		if(A[i]<=key){
			temp=A[i];
			A[i]=A[pivot];
			A[pivot]=temp;
			pivot++;
		}
	}
	temp = A[end];
	A[end]=A[pivot];
	A[pivot]=temp;
	return pivot;
}

int MaxWeightDifference(int *A, int length, int k){
	int start=0,end=length-1,return_value=-1;
	if(k>length-k)
		k=length-k;
	while(true){
		return_value = random_partition(A,start,end);
		if(return_value==k-1)
			break;
		else if(return_value>k-1)
			end=return_value-1;
		else
			start=return_value+1;
	}
	int sum_left=0,sum_right=0;
	for(int i=0;i<k;i++)
		sum_left+=A[i];
	for(int i=k;i<length;i++)
		sum_right+=A[i];
	return abs(sum_right- sum_left);
}

int main(){
	int num_tests,weights[MAX],n,k;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&n,&k);
		for(int j=0;j<n;j++)
			scanf("%d",weights+j);
		printf("%d\n",MaxWeightDifference(weights,n,k));
	}
	return 0;
}
