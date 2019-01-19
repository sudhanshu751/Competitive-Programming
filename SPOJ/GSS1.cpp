#include <cstdio>
#include <climits>

int max(int x, int y){
    return x>=y ? x : y ;
}

struct Node {
    int max_sum,total_sum,prefix_sum,suffix_sum ;
};

class SegmentTree{
    private :
        int *array;
        int size ;
        Node *st ;
        void buildSegmentTree(int left, int right, int index);
        Node queryHelper(int left,int right, int range_start, int range_end, int index);
        Node Merge(Node a, Node b);
    public :
        SegmentTree(int N=0);
        ~SegmentTree(){
            delete [] array;
            delete [] st ;
        }
        int query(int start_range, int end_range){
            return queryHelper(0,size-1,start_range,end_range,1).max_sum;
        }
};

SegmentTree::SegmentTree(int N):size(N){
    array = new int[size];
    st = new Node[4*size];
    for(int i=0;i<size;i++)
        scanf("%d",&array[i]);
    buildSegmentTree(0,size-1,1);
}

Node SegmentTree::Merge(Node leftNode, Node rightNode){
    Node resultNode ;
    resultNode.max_sum = max(max(leftNode.max_sum,rightNode.max_sum),
                             leftNode.suffix_sum + rightNode.prefix_sum );
    resultNode.total_sum = leftNode.total_sum + rightNode.total_sum ;
    resultNode.prefix_sum = max(leftNode.prefix_sum, leftNode.total_sum + rightNode.prefix_sum );
    resultNode.suffix_sum = max(rightNode.suffix_sum, rightNode.total_sum+leftNode.suffix_sum) ;
    return resultNode ;
}

void SegmentTree::buildSegmentTree(int left, int right, int index){
    if(left > right )
        return;
    else if(left == right){
        st[index].max_sum = st[index].prefix_sum = st[index].suffix_sum = st[index].total_sum = array[left];
        return;
    }
    int mid = left + (right-left)/2;
    buildSegmentTree(left,mid,2*index);
    buildSegmentTree(mid+1,right,2*index+1);
    st[index] = Merge(st[2*index], st[2*index+1]) ;
}

Node SegmentTree::queryHelper(int left, int right, int start_range, int end_range, int index){
    Node resultNode,leftNode,rightNode ;
    //CompleteOverlap
    if(start_range <= left && end_range >=right)
        return st[index];
    //NoOverlap
    else if(start_range > right || end_range < left){
        resultNode.max_sum = resultNode.total_sum = resultNode.prefix_sum = resultNode.suffix_sum = INT_MIN;
        return resultNode;
    }
    int mid = left + (right-left)/2;
    leftNode = queryHelper(left,mid,start_range,end_range,2*index);
    rightNode = queryHelper(mid+1,right,start_range,end_range,2*index+1);

    //NoOverlap with left child
    if(leftNode.max_sum == INT_MIN)
        return rightNode ;
    //NoOverlap with right child
    else if(rightNode.max_sum == INT_MIN)
        return leftNode ;
    //PartialOverlap with both left and right child
    else{
        resultNode = Merge(leftNode, rightNode);
        return resultNode;
    }
}

int main(){
    int N,M,x,y;
    scanf("%d",&N);
    SegmentTree myST(N);
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d%d",&x,&y);
        printf("%d\n",myST.query(--x,--y));
    }
    return 0;
}
