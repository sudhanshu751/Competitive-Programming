#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;

int main(){
	mp::cpp_int total = 0, difference =0 ;
	for(int i=0;i<10;i++){
		std::cin >> total >> difference ;
		std::cout << (total+difference)/2 << std::endl;
		std::cout << total - (total+difference)/2 << std::endl;
	}
	return 0;
}
