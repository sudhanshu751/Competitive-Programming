#include <stdio.h>
#include <stdlib.h>
#define MAX 200001
long long int Merge(int *A,int *left, int *right, int size){
	long long int i=0,j=0,k=0,mid = size/2,inversions=0;
	while(i<mid && j<(size-mid)){
		if(left[i]<=right[j]){
			A[k]=left[i];
			i++;
		}
		else{
			inversions+=(mid-i);
			A[k]= right[j];
			j++;
		}
		k++;
	}
	while(i<mid){
		A[k] = left[i];
		i++;k++;
	}
	while(j<(size-mid)){
		A[k]=right[j];
		j++;k++;
	}
	return inversions;
}

long long int  MergeSort(int *A, int size){
	if(size < 2)
		return 0;
	int mid = size/2;
	long long int left_inversion=0,right_inversion=0,total_inversion=0;
	int *left = (int *)malloc(sizeof(int)*mid);
	int *right = (int *)malloc(sizeof(int)*(size-mid));
	for(int i=0;i<mid;i++)
		left[i]=A[i];
	for(int i=0;i<size-mid;i++)
		right[i]= A[mid+i];

	left_inversion = MergeSort(left,mid);
	right_inversion = MergeSort(right,size-mid);
	total_inversion = left_inversion + right_inversion + Merge(A,left,right,size);
	free(left);
	free(right);
	return total_inversion;
}

int main(void){
	int num_tests,n,Array[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&n);
		for(int j=0;j<n;j++)
			scanf("%d",Array+j);
		printf("%lld\n",MergeSort(Array,n));
	}
	return 0;
}
