#include<stdio.h>
#define MAX 5001
#include <string.h>
int value(char a,char b){
	return (a-'0')*10 + (b-'0');
}

long long int numDecodings(char *str, long long int *decodings){
	int size = strlen(str),counter=1,val;
	char *tmp = str;
	while(*tmp){
		if(tmp > str && (val=value(*(tmp-1),*tmp)) >=10 && val <=26){
			decodings[counter]= (val%10 !=0) ? decodings[counter-1] + decodings[counter-2] : decodings[counter-2];
		}
		else
			decodings[counter] = decodings[counter-1];
		tmp++;
		counter++;
	}
	return decodings[size];
}

int main(void){
	char str[MAX];
	long long int decodings[MAX] = {0};
	while(scanf("%s",str) && (*str!='0')){
		decodings[0]  = 1;
		printf("%lld\n",numDecodings(str,decodings));
	}
	return 0;
}
