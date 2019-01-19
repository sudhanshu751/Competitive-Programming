#include <cstdio>
#include <unordered_map>
#define MAX 100001

long long int frequency(std::unordered_map<unsigned,unsigned> &mymap,unsigned x){
	std::unordered_map<unsigned,unsigned>::iterator it = mymap.find(x);
	return (it!=mymap.end())? it->second : 0;
}

void insert_map(std::unordered_map<unsigned,unsigned> &map, int x){
	std::unordered_map<unsigned,unsigned>::iterator it = map.find(x);
	if(it!=map.end())
		(it->second)++;
	else 
		map.insert(std::pair<unsigned,unsigned>(x,1));

}


long long int numPairs(int *A,int n, std::unordered_map<unsigned,unsigned> &map){
	long long int total_pairs=0,temp=0,num_odds=0,num_evens=0;
	for(int i=n-1;i>=0;i--){
		temp = (A[i]%2) ? num_odds : num_evens;
		if(temp>0){
				temp=temp-frequency(map,A[i])-frequency(map,A[i]^2);
				total_pairs+=temp;
		}
		insert_map(map,A[i]);
		(A[i]%2)? num_odds++ : num_evens++;
	}
	return total_pairs;
}

int main(){
	std::unordered_map<unsigned,unsigned> map;
	int num_tests,N,array[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		for(int j=0;j<N;j++)
			scanf("%d",array+j);
		map.clear();
		printf("%lld\n",numPairs(array,N,map));
	}
	return 0;
}
