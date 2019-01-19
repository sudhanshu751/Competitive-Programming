#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

int comp_func(const void *x, const void *y){
	int a = (*(int *)x) ;
	int b = (*(int *)y) ;
	if(a>b)
		return 1;
	else if(a < b)
		return -1;
	else 
		return 0;
}

int minFriends(int stamps_needed, int *array, int num_friends){
	int total = 0;
	qsort(array,num_friends,sizeof(array[0]),comp_func);
	for(int i=0;i<num_friends;i++)
		total+=array[i];
	if(total < stamps_needed)
		return -1;
	total = 0;
	int count = num_friends;
	while(count >=0 && total < stamps_needed){
		count--;
		total+=array[count];
	}
	return num_friends - count;
}

int main(void){
	int num_tests,stamps_needed,num_friends,array[MAX],answer;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&stamps_needed,&num_friends);
		for(int j=0;j<num_friends;j++){
			scanf("%d",array+j);
		}
		printf("Scenario #%d:\n",i+1);
		answer = minFriends(stamps_needed,array,num_friends);
		if(answer!=-1){
			printf("%d\n",answer);
		}else
			printf("impossible\n");
	}
	return 0;
}
