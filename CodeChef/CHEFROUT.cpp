#include<cstdio>
#include<cstring>
#define MAX 200000

void checkroutine(char *str);
int main(){
	int num_tests;
	char string[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%s",string);
		checkroutine(string);
	}
	return 0;
}

void checkroutine(char *str){
	if(strlen(str)==1){
		printf("yes\n");
		return;
	}
	str++;
	while(*str){
		if(*(str) < *(str-1)){
			printf("no\n");
			return;
		}
		else 
			str++;
	}
	printf("yes\n");
}
