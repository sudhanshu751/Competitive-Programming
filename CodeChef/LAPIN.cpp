#include<cstdio>
#include<cstring>
#define MAX 1001

bool IsLapindrome(char *str, int *frequency){
	if(strlen(str)<1)
		return false;
	if(strlen(str)==1)
		return true;

	int length=strlen(str);
	int mid=length/2;
	for(int i=0;i<mid;i++)
		frequency[str[i]-'a']++;
	if(length%2==1)
		mid++;
	for(int i=mid;i<length;i++)
		frequency[str[i]-'a']--;
	for(int i=0;i<26;i++)
		if(frequency[i])
			return false;
	return true;
}

int main(){
	int num_tests,frequency[26];
	char str[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%s",str);
		memset(frequency,0,sizeof(frequency));
		IsLapindrome(str, frequency) ? printf("YES\n") : printf("NO\n") ;
	}
	return 0;
}
