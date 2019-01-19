#include<cstdio>
#include<algorithm>
#define MAX 5000
int MinDifferenceOfSkill(int *A, int n);

int main(){
	short int num_tests;
        int num_horses, skills[MAX];
	scanf("%hd",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&num_horses);
		for(register int j=0;j<num_horses;j++)
			scanf("%d",skills+j);
		printf("%d\n",MinDifferenceOfSkill(skills,num_horses));
	}
	return 0;
}

int MinDifferenceOfSkill(int *A, int n){
	std::sort(A, A+n);
	int min_difference=0x7fffffff;
	for(int i=0;i<n-1;i++){
		if(A[i+1]-A[i] < min_difference)
			min_difference = A[i+1]-A[i];
	}
	return min_difference ;
}
