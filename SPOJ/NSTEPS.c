#include <stdio.h>

void printNumber(int x, int y);

int main(void){
	int num_tests, x, y;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&x,&y);
		printNumber(x,y);
	}
	return 0;
}

void printNumber(int x, int y){
	if((x%2==y%2) && (x-y==0 || x-y==2)){
		(x%2 && y%2) ? printf("%d\n",x+y-1) : printf("%d\n",x+y);
	}
	else 
		printf("No Number\n");
}
