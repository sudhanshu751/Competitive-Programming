#include<cstdio>
#include<cstring>
#define MAX 100001
void NumControlledVillages(char *);
int main(){
	char str[MAX];
	int num_tests;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%s",str);
		NumControlledVillages(str);
		printf("\n");
	}
	return 0;
}

void NumControlledVillages(char *str){
	if(strlen(str)==0){
		printf("%d %d",0,0);
		return ;
	}
	int numA=0,numB=0,temp=0;
	int i=0,length = strlen(str);
	while(i<length && str[i]=='.')
		++i;
	for(;i<length;i++){
		if(str[i]=='A'){
			numA++;
			while(i<length-1 && str[i+1]=='.'){
				++i;
				++temp;
			}
			if(str[i+1]=='A'){
				numA+=temp;
				temp=0;
			}
			else if(str[i+1]=='B') temp=0;
		}
		else if(str[i]=='B'){
			numB++;
			while(i<length-1 && str[i+1]=='.'){
				++i;
				++temp;
			}
			if(str[i+1]=='B'){
				numB+=temp;
				temp=0;
			}
			else if(str[i+1]=='A') temp=0;
		}
	}
	printf("%d %d",numA,numB);
}
