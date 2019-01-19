#include <cstdio>

bool IsRectangle(int a, int b, int c, int d){
	if(a==b)
		return c==d ;
	else if(a==c)
		return b==d ;
	else if(a==d)
		return b==c ;
	else return false;
}

int main(){
	int num_tests,a,b,c,d;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		IsRectangle(a,b,c,d) ?printf("YES\n") : printf("NO\n") ;
	}
	return 0;
}
