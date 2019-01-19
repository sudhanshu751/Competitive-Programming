#include <stdio.h>

void printCantorNumber(long long int N){
	long long int row_num =0,total_elements=0,top_element,bottom_element;
	while(total_elements < N){
		row_num++;
		total_elements+=row_num;
	}
	total_elements =((row_num-1)*(row_num))/2 + 1;
	if(row_num % 2){
		top_element = row_num - (N-total_elements);
		bottom_element = 1 + (N-total_elements);
	}
	else{
		top_element =  1 + (N-total_elements);
		bottom_element = row_num - (N-total_elements);
	}
	printf("TERM %lld IS %lld/%lld\n",N,top_element,bottom_element);
}

int main(void){
	int num_tests;
	long long int N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%lld",&N);
		printCantorNumber(N);
	}
	return 0;
}
