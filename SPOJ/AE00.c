#include <stdio.h>

int main(){
	int N,total_rectangles = 0;
	scanf("%d",&N);
	for(int i=1;i*i<=N;i++){
		total_rectangles += N/i - i +1;
	}
	printf("%d\n",total_rectangles);
	return 0;
}
