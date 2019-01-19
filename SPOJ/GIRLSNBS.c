#include <stdio.h>

int min(int x, int y){
	return x>=y ? y : x;
}

int minGenderRegularity(int G, int B);

int main(){
	int G,B;
	while(scanf("%d%d",&G,&B) && G!=-1 && B!=-1){
		printf("%d\n",minGenderRegularity(G,B));
	}
	return 0;
}
int minGenderRegularity(int G, int B){
	if(G==0)
		return B;
	else if(B==0)
		return G;
	else if(G==B)
		return 1;
	else return (int)(G+B)/(min(G,B)+1);
}
