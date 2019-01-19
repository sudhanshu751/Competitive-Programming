#include <cstdio>
#include <cstdlib>

bool spellBob(char *top, char *bottom){
	int b[6],o[6],bptr=-1,optr=-1;
	for(int i=0;i<3;i++){
		if(top[i]=='b' || bottom[i]=='b'){
			bptr++;
			b[bptr]=i;
		}
		if(top[i]=='o' || bottom[i]=='o'){
			optr++;
			o[optr]=i;
		}
	}

	for(int i=0;i<=bptr;i++)
		for(int k=0;k<=optr;k++)
			for(int j=0;j<bptr;j++)
				if(b[i]!=o[k] && b[i]!=b[j] && o[k]!=b[j])
					return true;
	return false;
}

int main(){
	int num_tests;
	char top[4],bottom[4];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%s%s",top,bottom);
		if(spellBob(top,bottom))
			printf("yes\n");
		else 
			printf("no\n");
	}
	return 0;
}
