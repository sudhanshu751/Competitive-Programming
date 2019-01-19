#include <cstdio>
#include <iostream>
#define MAX 200
void printFactorial(int input);

int main(){
	int num_tests,N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		printFactorial(N);
	}
	return 0;
}

void printFactorial(int input){
	if(input==0){
		std::cout << 1 <<std::endl; 
		return;
	}
	int fact[MAX]={0};
	int size=1,carry=0,digit=1;
	fact[0]=digit;
	for(int i=2;i<=input ;i++){
		carry=digit=0;
		for(int j=0;j<size;j++){
			digit = fact[j]*i + carry;
			fact[j]=digit%10;
			carry=digit/10;
		}
		while(carry){
			size++;
			fact[size-1] = carry%10;
			carry/=10;	
		}
	}
	for(int i=size-1;i>=0;i--)
		std::cout << fact[i] ;

	std::cout << std::endl ;

}
