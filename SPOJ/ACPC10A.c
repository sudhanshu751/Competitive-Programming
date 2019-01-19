#include <stdio.h>

void apOrGp(int a1,int a2,int a3){
	int d;
	if(a2-a1 == a3-a2){
		d=a2-a1;
		printf("AP %d\n",a3+d);
	}
	else{
		d=a2/a1;
		printf("GP %d\n",a3*d);
	}
}

int main(void){
	int a1,a2,a3;
	while(scanf("%d%d%d",&a1,&a2,&a3) && (a1 || a2 || a3)){
		apOrGp(a1,a2,a3);
	}
	return 0;
}
