#include <cstdio>
#include <algorithm>
#define MAX 1000000

bool DoesContain(int *Arr, int start, int end, int key){
	if(start>end)
		return false;
	int mid;
	while(start<=end){
		mid=start + (end-start)/2;
		if(Arr[mid]==key)
			return true ;
		else if(Arr[mid]>key)
			end=mid-1;
		else 
			start=mid+1;
	}
	return false ;
}

bool IsSequenceCorrect(int *sequence, int *sorted_sequence, int length, int key){
	if(length < 1 || (!DoesContain(sorted_sequence,0,length-1,key)))
		return false ;
	int start=0,end=length-1;
	for(int i=0;i<length-1;i++){
		if(DoesContain(sorted_sequence,start,end,sequence[i])){
			if(sequence[i]>key)
				end--;
			else if(sequence[i]<key)
				start++;
		}
		else 
			return false;
	}
	return key==sorted_sequence[start] ? true :false ;
}

int main(){
	int num_tests, sequence[MAX], sorted_sequence[MAX],length, rating ;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&length,&rating);
		for(int j=0;j<length;j++){
			scanf("%d",sequence+j);
			*(sorted_sequence+j)=*(sequence+j);
		}
		std::sort(sorted_sequence, sorted_sequence+length);
		IsSequenceCorrect(sequence,sorted_sequence,length,rating) ? printf("YES\n") : printf("NO\n") ;
	}
	return 0;
}