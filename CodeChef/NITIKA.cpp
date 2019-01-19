#include<cstdio>
#include<cstring>
#define MAXLEN 11
void printFullName(char *str){
	if(*str>='a' && *str <='z')
		putchar(*str - 'a' + 'A');
	else 
		putchar(*str);
	str++;
	while(*str){
		if(*str>='A' && *str<='Z')
			putchar(*str-'A'+'a');
		else 
			putchar(*str);
		str++;
	}
}

void printCapitalFirst(char *str){
	if(*str>='a' && *str<='z')
		*str = *str - 'a' +'A' ;
	printf("%c. ",*str);
}

void formatting(char *firstname, char *middlename, char *lastname){
	int index=0,ch ;
	char *ptr[3]={firstname, middlename, lastname} ;
	while((ch=getchar())!='\n'){
		if(ch==' '){
			*(ptr[index]) = '\0';
			index++;
		}
		else{
			*(ptr[index])=ch ;
			(ptr[index])++;
		}
	}
	*(ptr[index])='\0';

	if(index==0)
		printFullName(firstname);
	else if(index==1){
		printCapitalFirst(firstname);
		printFullName(middlename);
	}
	else{
		printCapitalFirst(firstname);
		printCapitalFirst(middlename);
		printFullName(lastname);
	}
}

int main(){
	int num_tests;
	char firstname[MAXLEN], middlename[MAXLEN], lastname[MAXLEN];
	scanf("%d",&num_tests);
	getchar();
	for(int i=0;i<num_tests;i++){
		firstname[0]=middlename[0]=lastname[0]='\0';
		formatting(firstname, middlename, lastname);
		printf("\n");
	}
	return 0;
}
