#include<cstdio>
void goodset(int n);
int main(){
	int numb_tests, n;
	scanf("%d",&numb_tests);
	for(int i=0; i<numb_tests; i++){
		scanf("%d",&n);
		goodset(n);
		printf("\n");
	}
	return 0;
}
void goodset(int n){
	printf("%d ",1);
	if(n==1)
		return;
	printf("%d ",2);
	if(n==2)
		return;
	for(int i=4,counter=3; counter<=n; counter++, i+=3)
		printf("%d ",i);

}
