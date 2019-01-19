#include <cstdio>
#include <string>
#include <unordered_map>
#include <iostream>
#define LEN 40
using namespace std;
void printSequenceCount(string str,unordered_map<string,int> &mymap){
	unordered_map<string,int>::iterator itr;
	for(int i=0;i<LEN-2;i++){
		itr = mymap.find(str.substr(i,3));
		(itr->second)++;
	}
	cout << mymap["TTT"] << " " <<mymap["TTH"] << " " << mymap["THT"] << " " <<mymap["THH"] << " " << mymap["HTT"] << " " << 
	mymap["HTH"] << " " << mymap["HHT"] <<" " << mymap["HHH"] ;
}

int main(){
	int num_tests,data_set;
	string str;
	unordered_map<string,int> mymap;
	mymap.insert(pair<string,int>("TTT",0));
	mymap.insert(pair<string,int>("TTH",0));
	mymap.insert(pair<string,int>("HTT",0));
	mymap.insert(pair<string,int>("THH",0));
	mymap.insert(pair<string,int>("THT",0));
	mymap.insert(pair<string,int>("HTH",0));
	mymap.insert(pair<string,int>("HHT",0));
	mymap.insert(pair<string,int>("HHH",0));
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		for(unordered_map<string,int>::iterator itr = mymap.begin();itr!=mymap.end();++itr){
			itr->second =0;
		}	
		cin >> data_set >> str;
		printf("%d ",data_set);
		printSequenceCount(str,mymap);
		printf("\n");
	}
	return 0;
}
