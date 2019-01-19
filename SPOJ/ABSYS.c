#include <stdio.h>
#include <string.h>
#define MAX 40
int stringToInt(char *str){
	int total = 0;
	while(*str){
		total = total*10 + (*str-'0');
		str++;
	}
	return total;
}

void findAnswer(){
	char input1[MAX],input2[MAX],input3[MAX];
	const char *m = "machula";
	int num1,num2,num3;
	scanf("%s%*c%*c%*c%s%*c%*c%*c%s",input1,input2,input3);
	if(strstr(input1,m)!=NULL){
		num2 = stringToInt(input2);
		num3 = stringToInt(input3);
		num1 = num3-num2;

	}
	else if(strstr(input2,m)!=NULL){
		num1 = stringToInt(input1);
		num3 = stringToInt(input3);
		num2 = num3-num1;
	}
	else{
		num1 = stringToInt(input1);
		num2 = stringToInt(input2);
		num3 = num1 +num2 ;
	}

	printf("%d + %d = %d",num1,num2,num3);
}

int main(){
	int num_Tests;
	scanf("%d",&num_Tests);
	for(int i=0;i<num_Tests;i++){
		findAnswer();
		printf("\n");
	}
	return 0;
}
