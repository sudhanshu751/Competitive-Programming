#include<iostream>
#include<cstdio>
#include<string>
#include<unordered_map>
#define MAX 100
using namespace std;

void IsForgottenWordRelevant(int k,int n, unordered_map<string,int> myhashtable, bool *valid){
	string temp;
	int l;
	for(int i=0;i<k;i++){
		scanf("%d",&l);
		for(int j=0;j<l;j++){
			cin>>temp;
			if(myhashtable.find(temp)!=myhashtable.end()){
				valid[myhashtable.find(temp)->second]=true;
			}
		}
	}
	for(int i=0;i<n;i++)
		valid[i] ? printf("YES ") : printf("NO ") ;
	printf("\n");
}

int main(){
	int num_tests,n,k;
	bool valid[MAX];
	string temp;
	unordered_map<string,int> myhashtable ;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&n,&k);
		myhashtable.clear();
		for(int j=0;j<n;j++){
			valid[j]=false;
			cin>>temp;
			myhashtable.insert(pair<string,int>(temp,j));
		}
		IsForgottenWordRelevant(k,n,myhashtable,valid);
	}
	return 0;
}
