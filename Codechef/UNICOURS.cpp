#include<cstdio>
#define MAXSIZE 110000
int maxnonprerequisite(int n, int *a);
int main(){
	int num_tests, n_courses, a[MAXSIZE];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&n_courses);
		for(register int j=0;j<n_courses;j++)
			scanf("%d",&a[j]);
		printf("%d\n",maxnonprerequisite(n_courses,a));
	}
	return 0;
}
int maxnonprerequisite(int n, int *a){
	int prerequisites = 0;
	for(register int i=0;i<n;i++){
		if(a[i]>prerequisites)
			prerequisites+=a[i]-prerequisites;
	}
	return n-prerequisites;
}
