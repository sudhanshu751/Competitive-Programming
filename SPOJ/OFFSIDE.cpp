    #include <cstdio>
    #include <algorithm>
    #define MAX 11
    bool isOffSide(int *A, int num_A, int *D, int num_D){
    	for(int i=0;i<num_A;i++)
    		scanf("%d",&A[i]);
    	for(int i=0;i<num_D;i++)
    		scanf("%d",&D[i]);
    	std::sort(A,A+num_A);
    	std::sort(D,D+num_D);
    	if(A[0] < D[1])
    		return true;
    	else return false;
    }
     
    int main(){
    	int A[MAX],D[MAX],num_A,num_D;
    	while(scanf("%d%d",&num_A,&num_D) && num_A!=0 && num_D!=0){
    		isOffSide(A,num_A,D,num_D) ? printf("Y\n") : printf("N\n") ;
    	}
    	return 0;
    } 
