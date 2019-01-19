#include <stdio.h>

int main(void){
	unsigned int N,pyani=0,temp ;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&temp);
		pyani = pyani^temp;
	}
	printf("%d\n",pyani);
	return 0;
}
