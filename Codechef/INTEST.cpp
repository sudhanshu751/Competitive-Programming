#include<cstdio>
int main(){
	int num_tests, divisor, input_number ;
	int divisible_numbers=0;
	scanf("%d%d",&num_tests, &divisor);
	for(register int i=0;i<num_tests;i++){
		scanf("%d",&input_number);
		if(input_number % divisor == 0)
			divisible_numbers++;
	}
	printf("%d",divisible_numbers);
	return 0;
}
