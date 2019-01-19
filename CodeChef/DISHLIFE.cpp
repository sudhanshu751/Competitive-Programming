#include<cstdio>
void dishoflife(int num_islands, int num_ingr);
int main(){
	int t,n,k;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d%d",&n,&k);
		dishoflife(n,k);
	}
	return 0;
}
void dishoflife(int num_islands, int num_ingr){
	bool collection[num_ingr]= {false}, flag ;
	int countN=num_islands, countK=num_ingr;
	int P,pi ;
	for(int i=0;i<num_islands;i++){
		scanf("%d",&P);
		flag=false ;
		for(int j=0;j<P;j++){
			scanf("%d",&pi);
			if(!collection[pi-1]){
				collection[pi-1]=true;
				countK--;
				flag=true;
			}
		}
		if(flag) countN--;
	}

	if(countK)
		printf("sad\n");
	else if(countN)
		printf("some\n");
	else 
		printf("all\n");
}
