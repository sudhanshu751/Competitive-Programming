#include <stdio.h>

int minCards(double max_hang_length){
	double hang_length = 0.0;
	int num_cards = 0;
	while(hang_length < max_hang_length){
		num_cards++;
		hang_length += 1.0/(num_cards+1) ;
	}
	return num_cards;
}

int main(){
	double max_hang_length;
	while(scanf("%lf",&max_hang_length) && max_hang_length != 0.0){
		printf("%d card(s)\n",minCards(max_hang_length));
	}
	return 0;
}
