#include <stdio.h>
#define MAX_COLUMN 20
#define MAX_ROW 10

void printMessage(char *string, int num_column, char (*matrix)[MAX_COLUMN]);

int main(void){
	int num_column;
	char matrix[MAX_ROW][MAX_COLUMN];
	char string[201];
	while(scanf("%d",&num_column) && num_column){
		scanf("%s",string);
		printMessage(string,num_column,matrix);
		printf("\n");
	}
	return 0;
}


void printMessage(char *string, int num_column, char (*matrix)[MAX_COLUMN]){
	int num_rows=0;
	int temp1=0,temp2=0;
	while(*string){
		temp1=temp2=0;
		for(int i=0;*string && i<num_column;string++,i++){
			matrix[num_rows][i]=*string;
			temp1=1;
		}
		if(temp1)
			num_rows++;

		for(int i=num_column-1;*string && i>=0 ; string++,i--){
			matrix[num_rows][i]=*string;
			temp2=1;
		}
		if(temp2)
			num_rows++;
	}
	for(int i=0;i<num_column;i++){
		for(int j=0;j<num_rows;j++)
			printf("%c",matrix[j][i]);
	}
}
