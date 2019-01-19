#include <stdio.h>
int lastDigit(int base, int power){
	base  = base %10;
	if(power == 0)
		return 1;
	else if(base == 0)
		return 0;
	power = power % 4 ? power % 4 : 4;
	int last_digit = 1 ;
	for(int i=1;i<=power;i++){
		last_digit = (last_digit*base)%10;
	}	
	return last_digit;
}

int main(){
	int num_tests, a, b ;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",lastDigit(a,b));
	}
	return 0;
}
