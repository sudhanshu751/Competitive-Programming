#include <stdio.h>
#define MAX 10001
int numCandy(int *candy_list, int size,int total_candies){
	int avg = total_candies / size;
	int candies_to_move = 0;
	for(int i=0;i<size;i++)
		if(candy_list[i]>avg)
			candies_to_move+=candy_list[i]-avg;
	return candies_to_move;
}

int main(void){
	int N,candy_list[MAX]={0},total_candies=0;
	while(scanf("%d",&N) && N!=-1){
		total_candies=0;
		for(int i=0;i<N;i++){
			scanf("%d",candy_list+i);
			total_candies+=candy_list[i];
		}
		if(total_candies%N)
			printf("%d\n",-1);
		else 
			printf("%d\n",numCandy(candy_list,N,total_candies));
	}
	return 0;
}
