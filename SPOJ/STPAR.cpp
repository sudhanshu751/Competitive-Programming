#include <cstdio>
#include <stack>
#define MAX 1001
bool isReorderingPossible(int *A, int size);

int main(){
	int trucks[MAX],size;
	while(scanf("%d",&size) && size!=0){
		for(int j=0;j<size;j++){
			scanf("%d",trucks+j);
		}
		isReorderingPossible(trucks,size) ? printf("yes\n") : printf("no\n") ;
	}
	return 0;
}
bool isReorderingPossible(int *A, int size){
	std::stack<int> street ;
	int trucknumber_expected = 1 ; 
	for(int i=0;i<size;i++){
		if(A[i]==trucknumber_expected)
			trucknumber_expected++;
		else if(A[i] > trucknumber_expected){
			while(!street.empty() && street.top() ==trucknumber_expected){
				street.pop();
				trucknumber_expected++;
			}
			if(!street.empty() && A[i]> street.top())
				return false;
			else
				street.push(A[i]);
		}
		else
			return false;

	}
	while(!street.empty() && trucknumber_expected==street.top()){
		trucknumber_expected++;
		street.pop();
	}
	return trucknumber_expected == size+1 ? true : false;
}
