#include <cstdio>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

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
	mp::cpp_int fact = input;
	if(input ==0)
		std::cout << 0 << std::endl;
	else if(input < 0)
		std::cout << input << std::endl;
	for(input--;input;input--){
		fact *= input;
	}
	
	std::cout << fact << std::endl;
}
