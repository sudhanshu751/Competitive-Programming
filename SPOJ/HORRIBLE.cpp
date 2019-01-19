#include <cstdio>

class SegmentTree{
	private :
		int size;
		long long int *array;
		long long int *st;
		long long int *lazy;
		void buildSegmentTree();
		long long int queryHelper(int left,int right,int range_start,int range_end,int index);
		void updateHelper(int left,int right,int range_start,int range_end,int index,long long int increment);

	public :
		SegmentTree(int N=0);
		~SegmentTree(){
			delete [] array;
			delete [] st;
			delete [] lazy;
		}
		long long int query(int range_start,int range_end);
		void update(int range_start,int range_end,long long int increment){
			updateHelper(0,size-1,range_start,range_end,1,increment);
		}
};

SegmentTree::SegmentTree(int N):size(N){
	array = new long long int[size];
	st = new long long int[4*size];
	lazy = new long long int[4*size];
	for(int i=0;i<size;i++)
		array[i]=0;
	buildSegmentTree();
}

void SegmentTree::buildSegmentTree(){
	for(int i=0;i<4*size;i++){
		st[i]=lazy[i]= 0;
	}
}

long long int SegmentTree::query(int range_start,int range_end){
	return queryHelper(0,size-1,range_start,range_end,1);
}

long long int SegmentTree::queryHelper(int left,int right,int range_start,int range_end,int index){
	
	if(left > right)
		return 0;
	
	if(lazy[index]!=0){
		st[index]+= ((right-left+1)*lazy[index]);
		if(left!=right){
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		lazy[index] = 0;
	}
	int mid = left +(right-left)/2;

	if(left > range_end || right < range_start)
		return 0;
	else if(range_start <= left && range_end >= right)
		return st[index];
	else{
		return   queryHelper(left,mid,range_start,range_end,2*index)+
			queryHelper(mid+1,right,range_start,range_end,2*index+1);
	}
}


void SegmentTree::updateHelper(int left,int right,int range_start,int range_end,int index,long long int increment){
	
	if(lazy[index]!=0){
		st[index]+= ((right-left+1)*lazy[index]);
		if(left!=right){
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		lazy[index] = 0;
	}

	int mid = left +(right-left)/2;

	if(left > range_end || right < range_start)
		return;
	else if(range_start <= left && range_end >= right){
		st[index] += ((right-left+1)*increment) ;
		if(left!=right){
			lazy[2*index]+=increment;
			lazy[2*index+1] +=increment;
		}
		
	}
	else{
		updateHelper(left,mid,range_start,range_end,2*index,increment);
		updateHelper(mid+1,right,range_start,range_end,2*index+1,increment);
		st[index] = st[2*index] + st[2*index+1];
	}

}

int main(){
	int num_tests,N,C,is_update,p,q;
	long long int v;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&N,&C);
		SegmentTree *myST = new SegmentTree(N); // SCOPE
		for(int j=0;j<C;j++){
			scanf("%d",&is_update);
			if(is_update){
				scanf("%d%d",&p,&q);
				--p;--q;
				printf("%lld\n",(*myST).query(p,q));
			}
			else{
				scanf("%d%d%lld",&p,&q,&v);
				--p;--q;
				(*myST).update(p,q,v);
			}
		}
		delete myST;
	}
	return 0;
}
