#include<cstdio>
#include<cstring>
#define MAX 100002

void PrintSequence(int *digits);

int main(){
	int num_tests, digits[10]={0};
	char str[MAX], *ptr=NULL ;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%s",str);
		ptr=str;
		memset(digits,0,sizeof(digits));
		while(*ptr){
			digits[*ptr - '0']++;
			ptr++;
		}
		PrintSequence(digits);
		printf("\n");
	}
	return 0;
}

void PrintSequence(int *digits){
	for(int i=int('A'), j=int('Z'); i<=j;i++){
		if((i%10==i/10) && (digits[i%10]>=2))
			printf("%c",char(i));
		else if((i%10!=i/10) && digits[i%10]>=1 && digits[i/10]>=1)
		       printf("%c",char(i));	
	}
}
