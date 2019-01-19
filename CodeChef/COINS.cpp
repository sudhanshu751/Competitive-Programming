#include<cstdio>
#include<unordered_map>
#include<utility>
using namespace std;
unordered_map<int, long long int> myhashtable;

long long int MaxCoins(int n);

int main(){
	int goldcoin;
	while(scanf("%d",&goldcoin) != EOF)
		printf("%lld\n",MaxCoins(goldcoin));
	return 0;
}

long long int MaxCoins(int n){
	if(n<=4) return n;
	unordered_map<int, long long int>::iterator itr = myhashtable.find(n);

	if(itr!=myhashtable.end())
		return itr->second ;
	else{
		long long int temp = MaxCoins(n/2) + MaxCoins(n/3) + MaxCoins(n/4) ;
		temp = (n>temp) ? n :temp;
		myhashtable.insert(pair<int, long long int>(n,temp)) ;
		return temp;
	}
}
