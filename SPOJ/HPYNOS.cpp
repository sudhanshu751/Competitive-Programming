#include <cstdio>
#include <unordered_set>

long long int isHappyNumber(long long int N,std::unordered_set<long long int> &mymap){
	long long int sum=0,digit,break_count=0,temp;
	if(N==0)
		return -1;
	else if(N==1)
		return 0;
	while(N!=1){
		sum=0;
		temp = N;
		mymap.insert(N);
		break_count++;
		while(temp){
			digit = temp%10;
			temp /= 10;
			sum += (digit*digit);
		}
		if(mymap.find(sum)!=mymap.end())
			return -1;
		N=sum;
	}
	return break_count;
}

int main(void){
	long long int N;
	std::unordered_set<long long int> mymap;
	scanf("%lld",&N);
	mymap.clear();
	printf("%lld\n",isHappyNumber(N,mymap));
	return 0;
}
