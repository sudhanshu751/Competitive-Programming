#include <stdio.h>

void NGM(long long int N);


int main(void){
	long long int N;
	scanf("%lld",&N);
	NGM(N);
	return 0;
}
void NGM(long long int N){
	if(N%10 == 0)
		printf("%d\n",2);
	else printf("%d\n%d\n",1,(int)(N%10));

}
