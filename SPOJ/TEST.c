#include <stdio.h>

int main(){
	short int input ;
	for(;scanf("%hd",&input) && input!=42;)
		printf("%hd\n",input);
	return 0;
}
