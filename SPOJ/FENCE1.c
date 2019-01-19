#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

double area(int length){
	if(length == 0)
		return 0.0;
	double len = (double) length ;
	return (len*len)/(2*PI);
}

int main(void){
	int length;
	while(scanf("%d",&length) && length!=0){
		printf("%0.2lf\n",area(length));
	}
}	
