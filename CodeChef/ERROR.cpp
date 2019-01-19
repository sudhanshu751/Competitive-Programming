#include<cstdio>
#include<cstring>
#define MAX 100001

bool GoodOrBadString(char *str);

int main(){
	int num_tests;
	char str[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%s",str);
		GoodOrBadString(str) ? printf("Good\n") :printf("Bad\n");
	}
	return 0;
}

bool GoodOrBadString(char *str){
	if(strlen(str) < 3)
		return false;
	char *end = str + (strlen(str)-3);
	while(str<=end){
		if((*str=='0' && *(str+1)=='1' && *(str+2)=='0')
			|| (*str=='1' && *(str+1)=='0' && *(str+2)=='1'))
			return true;
		str++;
	}
	return false;
}
