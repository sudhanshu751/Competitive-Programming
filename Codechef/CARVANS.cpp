#include<cstdio>
int CountCarsAtMaxSpeed(int n);
int main(){
	int num_tests, n;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&n);
		printf("%d\n",CountCarsAtMaxSpeed(n));
	}
	return 0;
}

int CountCarsAtMaxSpeed(int n){
	int count=1,previous_element, next_element;
	scanf("%d",&previous_element);
	if(n==1)
		return 1;
	for(int i=1;i<n;i++){
		scanf("%d",&next_element);
		if(next_element<=previous_element){
			count++;
			previous_element=next_element;
		}
	}
	return count;

}
