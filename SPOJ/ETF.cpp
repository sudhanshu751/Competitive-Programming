#include <cstdio>
#include <unordered_set>
 
long long int totientNumber(long long int N, std::unordered_set<long long int> &myset);
 
int main(){
	int num_tests;
	long long int N;
	std::unordered_set<long long int> myset ;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%lld",&N);
		myset.clear();
		printf("%lld\n",totientNumber(N,myset));
	}
	return 0;
}
 
long long int totientNumber(long long int N, std::unordered_set<long long int> &myset){
	if(N<2)
		return N;
	long long int n = N;
	for(int i=2;i*i <=n;i++){
		if(n%i == 0){
				myset.insert(i);
				while(n%i==0)
					n/=i ;
			
		}
	}
	if(n!=1)
		myset.insert(n);
	for(std::unordered_set<long long int>::iterator itr = myset.begin();itr!=myset.end();++itr){
		N = (N*((*itr)-1))/(*itr) ;
	}
	
	return N;
}
