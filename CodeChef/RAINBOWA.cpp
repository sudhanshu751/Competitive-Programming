#include<cstdio>
#define MAX 100

bool Is_Rainbow_Array(short int *A, int n);

int main(){
	short int num_tests, n, A[MAX];
	scanf("%hd",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%hd",&n);
		for(int j=0;j<n;j++)
			scanf("%hd",A+j);
		if(Is_Rainbow_Array(A,n))
			printf("yes\n");
		else 
			printf("no\n");
	}
	return 0;
}

bool Is_Rainbow_Array(short int *A, int n){
	int i,j,current_item=1;
	for(i=0,j=n-1;i<=j;i++,j--){
		if(A[i]==A[j]){
			if(A[i]!=current_item){
				if(A[i]==current_item+1)
					current_item++;
				else 
					return false;
			}
		}
		else 
			return false;
	}
	return current_item==7 ? true : false ;
}
