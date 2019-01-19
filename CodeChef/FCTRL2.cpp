#include<cstdio>
#include<boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision ;

mp::cpp_int factorial(short unsigned int x);

int main(){
	
	short unsigned int num_tests,numb;
	scanf("%hd",&num_tests);
	for(register short unsigned int i = 0; i<num_tests; ++i){
		scanf("%hd",&numb);
		std::cout << factorial(numb) << std::endl ;
	}
	return 0;
}

mp::cpp_int factorial(short unsigned int x){
	mp::cpp_int answer = x;
	for(--x;x>1;--x)
		answer *= x ;
	return answer ; 
}
