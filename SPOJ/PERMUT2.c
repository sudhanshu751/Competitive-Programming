#include <stdio.h>
#define MAX 100001

int isAmbiguous(int *A, int size){
	for(int i=0;i<size;i++){
		if(A[A[i]-1] != i+1)
			return 0;
	}

	return 1;
}

int main(void){
	int n, Array[MAX];
	while(scanf("%d",&n) && n!=0){
		for(int i=0;i<n;i++)
			scanf("%d",Array+i);
		isAmbiguous(Array,n) ? printf("ambiguous\n") : printf("not ambiguous\n");
	}
	return 0;
}
