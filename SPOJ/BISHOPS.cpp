#include<cstdio>
#include<cstring>
#define MAX 103
char *Num_Bishops(char *str);
void Doubling(char *str);
void Subract_By_2(char *str);

int main(){
	char s[MAX];
	while(scanf("%s",s)!=EOF)
		printf("%s\n",Num_Bishops(s));
	return 0;
}

char *Num_Bishops(char *str){
	if(strlen(str)==1 && (*str=='0' || *str=='1'))
		return str;
	for(int i =strlen(str); i>=0; i--)
		str[i+1]=str[i] ;
	str[0]='0';
	Doubling(str);
	Subract_By_2(str);
	return (*str=='0') ? str+1 : str ;
}

void Doubling(char *str){
	int carry=0,sum=0;
	char *ptr = str + (strlen(str)-1) ;
	while(ptr>str){
		sum = (*ptr-'0')*2 +carry ;
		*ptr = sum%10 +'0' ;
		carry = sum/10 ;
		ptr--;
	}
	*ptr=carry+'0';
}

void Subract_By_2(char *str){
	char *ptr = str + (strlen(str)-1) ;
	if(*ptr>='2'){
		*ptr = *ptr - 2;
		return ;	
	}
	*ptr = *ptr + 10 -2 ; //case of last digit being 0, borrow from left digits
	ptr--;
	while(ptr>=str && *ptr=='0'){
		*ptr='9';
		ptr--;
	}
	*ptr = *ptr-1 ;
}
