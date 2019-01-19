#include <cstdio>
#include <climits>
struct Node{
	int total_sum,prefix_sum,suffix_sum,maximum_sum;
};

int max(int a, int b){
	return a>=b ? a : b;
}

class SegmentTree{
	private :
		int size;
		int *array;
		Node *st;
		void buildSegmentTree(int index,int left,int right);
		Node queryHelper(int index,int left,int right,int start_range,int end_range);
		Node updateHelper(int index,int left,int right,int start_range,int end_range,int increment);
		Node merge(Node leftchild, Node rightchild);
	public :
		SegmentTree(int N=0);
		~SegmentTree(){
			delete [] array;
			delete [] st;
		}
		int query(int start_range,int end_range);
		void update(int start_range,int end_range,int increment);

};

SegmentTree::SegmentTree(int N):size(N){
	array = new int[size];
	st = new Node[4*size];
	for(int i=0;i<size;i++){
		scanf("%d",&array[i]);
	}
	buildSegmentTree(1,0,size-1);
}

int SegmentTree::query(int start_range,int end_range){
	return queryHelper(1,0,size-1,start_range,end_range).maximum_sum;
}

void SegmentTree::update(int start_range,int end_range,int increment){
	updateHelper(1,0,size-1,start_range,end_range,increment);
}

Node SegmentTree::merge(Node leftchild,Node rightchild){
	Node result;
	if(leftchild.maximum_sum ==INT_MIN)
		return rightchild;
	else if(rightchild.maximum_sum == INT_MIN)
		return leftchild;
	else{
		result.total_sum = leftchild.total_sum + rightchild.total_sum;
		result.prefix_sum = max(leftchild.prefix_sum,leftchild.total_sum+rightchild.prefix_sum);
		result.suffix_sum = max(rightchild.suffix_sum,rightchild.total_sum+leftchild.suffix_sum);
		result.maximum_sum = max(leftchild.suffix_sum+rightchild.prefix_sum,max(leftchild.maximum_sum,rightchild.maximum_sum));
	return result;
	}
}

void SegmentTree::buildSegmentTree(int index,int left,int right){
	if(left == right){
		st[index].maximum_sum = st[index].prefix_sum = st[index].suffix_sum = st[index].total_sum = array[left];
		return;
	}
	int mid = left + (right-left)/2;
	buildSegmentTree(2*index,left,mid);
	buildSegmentTree(2*index+1,mid+1,right);
	st[index] = merge(st[2*index],st[2*index+1]);
}

Node SegmentTree::queryHelper(int index,int left,int right,int start_range,int end_range){
	Node result,leftchild,rightchild ;
	if(left > end_range || right < start_range){
		result.maximum_sum = result.prefix_sum = result.suffix_sum = result.total_sum = INT_MIN;
		return result;
	}
	else if(start_range <= left && end_range >=right)
		return st[index];
	else{
		int mid = left+(right-left)/2;
		leftchild = queryHelper(2*index,left,mid,start_range,end_range);
		rightchild = queryHelper(2*index+1,mid+1,right,start_range,end_range);
		return result = merge(leftchild,rightchild);
	}
}

Node SegmentTree::updateHelper(int index,int left,int right,int start_range,int end_range,int increment){
	Node leftchild,rightchild;
	if(left==right && left == start_range){
		array[left] = increment;
		st[index].maximum_sum = st[index].prefix_sum = st[index].suffix_sum = st[index].total_sum = array[left];
		return st[index];
	}
	else if(left > end_range || right < start_range){
		return st[index];
	}
	int mid = left + (right-left)/2 ;
	leftchild = updateHelper(2*index,left,mid,start_range,end_range,increment);
	rightchild = updateHelper(2*index+1,mid+1,right,start_range,end_range,increment);
	return st[index] = merge(leftchild,rightchild);
}

int main(){
	int N,M,operation,x,y;
	scanf("%d",&N);
	SegmentTree myST(N);
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&operation,&x,&y);
		if(operation){
			--x;--y;
			printf("%d\n",myST.query(x,y));
		}
		else{	--x;
			myST.update(x,x,y);
		}
	}
	return 0;
}

