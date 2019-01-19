#include<cstdio>
#include<cstring>
#define MAX 100001

int root(int *id, int x){
	int i=x;
	while(i!=id[i])
		i=id[i];
	id[x]=i;
	return i;
}

void quick_union(int *id, int x, int y){
	int root_x = root(id,x);
	int root_y = root(id,y);
	if(root_x != root_y)
		id[root_x]=root_y ;
}

bool checkPalindrome(char *str){
	int i=0,j=strlen(str)-1 ;
	while(i<j){
		if(str[i]!=str[j])
			return false;
		i++;
		j--;
	}
	return true;
}

bool checkPeriodic(char *str, int length, int period){
	int i=0;
	while(i+period < length){
		if(str[i]!=str[i+period])
			return false;
		i++;
	}
	return true;
}

void GeneratePeriodicPalindrome(int *id, char *str, int N, int P){
	for(int i=0,j=N-1;i<j;i++,j--)
		quick_union(id,i,j);
	for(int i=0;i+P<N;i++)
		quick_union(id,i,i+P);
	for(int i=0;i<N;i++)
		id[i]=root(id,i);

	int subset1_head = id[0];
	int counter=0,flag=0;
	for(;counter<N;counter++){
		if(id[counter]==subset1_head)
			str[counter]='a';
		else{
			flag=1;
			str[counter]='b';
		}
	}
	str[counter]='\0';
	if(flag && checkPalindrome(str) && checkPeriodic(str,N,P))
		printf("%s\n",str);
	else 
		printf("impossible\n");
}

int main(){
	int num_tests, N, P, id[MAX];
	char str[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&N,&P);
		for(int j=0;j<N;j++)
			id[j]=j;
		GeneratePeriodicPalindrome(id,str,N,P);
	}
	return 0;

}
