#include<cstdio>
unsigned long int Z(unsigned long int x);

int main(){
	unsigned long int num_tests,numb ;
	scanf("%lu",&num_tests);
	for(register unsigned long int i=0; i<num_tests;i++){
		scanf("%lu",&numb);
		printf("%lu\n",Z(numb));
	}
	return 0;
}

unsigned long int Z(unsigned long int x){
	unsigned long int num_zeroes = 0;
	for(register unsigned long int i = 5; i<=x; i*=5){
		num_zeroes += x/i ;
	}
	return num_zeroes ; 
}
