#include <stdio.h>
#include <stdlib.h>
#define MAX 1000 // Some max value >26
void printPopulation(int m){
	int d1,d2,d3,case_num;
	long long int k;

	d1 = abs(m-0)%26;
	d2 = m>=2  ? abs(m-2)%26 : MAX;
	d3 = m>=10 ? abs(m-10)%26 : MAX;
	if(d1<=d2 && d1<=d3)
		case_num=1;
	else if(d2<=d1 && d2<=d3)
		case_num=2;
	else case_num=3;
	switch(case_num){
		case 1:
			k = abs(m-d1-0)/26;
			k = ((long long int)1) << k;
			printf("%lld %d %d\n",k,0,0);
			break;
		case 2:	

			k = abs(m-d2-2)/26;
			k = ((long long int)1) << k;
			printf("%d %lld %d\n",0,k,0);
			break;
		case 3:

			k = abs(m-d3-10)/26;
			k = ((long long int)1) << k;
			printf("%d %d %lld\n",0,0,k);
			break;
	}

}

int main(){
	int num_tests,N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		printPopulation(N-1);
	}
	return 0;
}
