#include <cstdio>
#include <unordered_map>
std::unordered_map<long long int, long long int> coin_map;
long long int goldCoins(long long int N);
int main(){
	long long int N;
	while(scanf("%lldd",&N)!=EOF){
		coin_map.clear();
		printf("%lld\n",goldCoins(N));
	}
	return 0;
}
long long int goldCoins(long long int N){
	if (N<5)
		return N;
	std::unordered_map<long long int,long long int>::iterator itr = coin_map.find(N);
	if(itr!=coin_map.end()){
		return itr->second;
	}
	long long int sub_coins = 0;
	for(int i=2;i<5;i++){
		sub_coins +=goldCoins(N/i);
	}
	sub_coins = N > sub_coins ? N : sub_coins ;
	coin_map.insert(std::pair<long long int, long long int>(N,sub_coins));
	return sub_coins;
}
