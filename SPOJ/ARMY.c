#include <stdio.h>

void whoWinsWar(int NG, int NM){
	int strongest_G=-1, strongest_MG=-1,temp;
	for(int i=0;i<NG;i++){
		scanf("%d",&temp);
		if(temp > strongest_G)
			strongest_G = temp;
	}
	for(int i=0;i<NM;i++){
		scanf("%d",&temp);
		if(temp > strongest_MG)
			strongest_MG = temp;
	}
	strongest_G >= strongest_MG ? printf("Godzilla\n") : printf("MechaGodzilla\n") ;

}

int main(void){
	int num_tests,NG,NM ;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&NG,&NM);
		whoWinsWar(NG,NM);
	}
	return 0;
}
