#include<cstdio>
#include<string>
#include<map>
#define MAXSTRLEN 11
#define MAXINGR 4
void findcommon(char dish1[][MAXSTRLEN],char dish2[][MAXSTRLEN]);

int main(){
	int numtests;
	char dish1[MAXINGR][MAXSTRLEN],dish2[MAXINGR][MAXSTRLEN];
	scanf("%d",&numtests);
	for(int i=0; i<numtests; ++i){
		for(int j=0; j<MAXINGR; ++j)
			scanf("%s",dish1[j]);
		for(int j=0; j<MAXINGR; ++j)
			scanf("%s",dish2[j]);
		findcommon(dish1, dish2);
	}
	return 0;
}

void findcommon(char dish1[][MAXSTRLEN],char dish2[][MAXSTRLEN]){
	int similar_ingr =0;
	std::map<std::string,char> mymap ;
	for( int i=0; i< MAXINGR; i++)
		mymap.insert(std::pair<std::string,char> (std::string(dish1[i]),'0'));
	for( int i=0; i<MAXINGR; i++){
		if(mymap.find(std::string(dish2[i])) != mymap.end())
			similar_ingr++;
		if(similar_ingr == 2){
			printf("similar\n");
			return;
		}
	}
	printf("dissimilar\n");
}
