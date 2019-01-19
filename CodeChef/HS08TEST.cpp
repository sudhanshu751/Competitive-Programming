#include<cstdio>
int main(){
	int withdrawl;
	float total;
	scanf("%d%f",&withdrawl, &total);
	if((withdrawl%5==0) && (total - withdrawl - 0.50f >=0.0f))
		printf("%.2f",total-withdrawl-0.50f);
	else 
		printf("%.2f",total);
	return 0;
}
