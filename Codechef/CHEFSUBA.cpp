#include<cstdio>
#define MAXSIZE 100002
int maxsubarray(int n, int k, bool *array,int startindex);
int main(){
	int n, k, p, temp,startindex;
	bool A[MAXSIZE];
	char commands[MAXSIZE];
	while(scanf("%d%d%d",&n,&k,&p)!=EOF){
		startindex=0;
		for(int i=0;i<n;i++)
		{	scanf("%d",&temp);
			A[i]=(temp)?true:false ;
		}
		scanf("%s",commands);
		
		for(int i=0;i<p;i++){
			if(commands[i]=='!'){
				startindex--;
				startindex = (n+startindex%n)%n;
			}
			else
				printf("%d\n",maxsubarray(n,k,A,startindex));
		}
	}
	return 0;
}

int maxsubarray(int n, int k, bool *array,int startindex){
	int tail=startindex, head=(startindex+k-1)%n, steps=n-k;
	int numb_ones=0,max_ones=0;
	for(register int i=0, j=startindex;i<k;i++,j++){
		if(array[j%n]==true)
			numb_ones++;
	}
	max_ones=numb_ones;
	if(max_ones==k)
		return max_ones;
	for(register int i=0;i<steps;i++){
		if(array[(head+1)%n]==true && array[tail]==false){
			numb_ones++;
			max_ones=(numb_ones>max_ones)?numb_ones:max_ones;
			if(max_ones==k)
				return max_ones;
		}
		else if(array[(head+1)%n]==false && array[tail]==true)
			numb_ones--;
		head=(head+1)%n;
		tail=(tail+1)%n;
	}
	return max_ones;
}

