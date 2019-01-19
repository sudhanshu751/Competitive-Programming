#include <cstdio>
#include <cstdlib>
#include <cmath>
#define REM 1000000007

unsigned long long int gcd(unsigned long long int a, unsigned long long int b){
	if(a==0)
		return b;
	else if(b==0)
		return a;
	unsigned long long int remainder;
	while(b){
		remainder = a%b;
		a=b;
		b=remainder;
	}
	return a;
}

unsigned long long int modularPower(unsigned long long int x,unsigned long long int p,unsigned long long int divisor){
	if(x==0 && p==0)
	{
		printf("Not possible\n");
		return 0;
	}
	else if(p==0)
		return 1;
	else if(p==1)
		return x;
	unsigned long long int halfpower;
	if(p%2){
		halfpower = gcd(modularPower(x,(p-1)/2,divisor),divisor) ;
		return gcd(halfpower*halfpower*x,divisor);
	}
	else{
		halfpower = gcd(modularPower(x,p/2,divisor),divisor);
		return gcd(halfpower*halfpower,divisor);
	}
}

unsigned long long int Power(unsigned long long int x,unsigned long long int p,unsigned long long int divisor){
	if(x==0 && p==0)
		return 0;
	else if(p==0)
		return 1%divisor;
	else if(p==1)
		return x%divisor;
	unsigned long long int halfpower;
	if(p%2){
		halfpower = Power(x,(p-1)/2,divisor)%divisor ;
		return (halfpower*halfpower*x)%divisor;
	}
	else{
		halfpower = Power(x,p/2,divisor)%divisor;
		return (halfpower*halfpower)%divisor;
	}
}

int modularGcd(unsigned long long int a,unsigned long long int b,unsigned long long int n){
	if(a==b){
		return ((Power(a%REM, n, REM)%REM) + (Power(b%REM, n, REM)%REM))%REM ;
	}
	
	unsigned long long int divisor = a-b;
	return gcd((modularPower(gcd(a,divisor),n,divisor))%REM +
			(modularPower(gcd(b,divisor),n,divisor))%REM ,divisor) % REM;
}

int main(){
	int num_tests;
	unsigned long long int a,b,n;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%llu%llu%llu",&a,&b,&n);
		printf("%d\n",modularGcd(a,b,n));
	}
	return 0;
}
