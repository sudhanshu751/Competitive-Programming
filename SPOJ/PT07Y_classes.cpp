#include <cstdio>

class WQUwPC{
	private :
		int *nodes;
		int *rank;
		int size;
	public :
		WQUwPC(int N):size(N)
		{
			nodes = new int[size];
			rank = new int[size];
			for(int i=0;i<size;i++){
				nodes[i]=i;
				rank[i]=0;
			}
		}
		~WQUwPC(){
			delete [] nodes;
			delete [] rank;
		}
		const bool isConnected(int a, int b);
		void Union(int a, int b);
		int findroot(int x);
};

int main(){
	int N,M,u[20001],v[20001];
	scanf("%d%d",&N,&M);
	WQUwPC dsu(N);
        for(int i=0;i<M;i++){
		scanf("%d%d",u+i,v+i);
		u[i]--;
		v[i]--;
	}
	bool isGraphTree = true;
	for(int i=0;i<M;i++){
		if(dsu.isConnected(u[i],v[i])){
			isGraphTree = false ;
			break;
		}
		else
			dsu.Union(u[i],v[i]);
	}
	if(isGraphTree){
		int global_root = dsu.findroot(0);
		for(int i=1;i<N;i++){
			if(dsu.findroot(i)!=global_root){
				isGraphTree = false;
				break;
			}
		}
	}
	isGraphTree ? printf("YES\n") : printf("NO\n");
	return 0;
}

const bool WQUwPC::isConnected(int a, int b){
	return findroot(a) == findroot(b) ;
}

int WQUwPC::findroot(int x){
	int current_parent = x, root;
	while(x!=nodes[x]){
		x = nodes[x];
	}
	root = x;
	x = current_parent; 
	while(x!= nodes[x]){
		current_parent = nodes[x];
		nodes[x] = root;
		x = current_parent;
	}
	return root;
}

void WQUwPC::Union(int a, int b){
	if(isConnected(a,b))
		return ;
	int root_a = findroot(a);
	int root_b = findroot(b);

	if(rank[root_a] >= rank[root_b]){
		rank[root_a] = (rank[root_a] == rank[root_b])? rank[root_a] +1 : rank[root_a];
		nodes[root_b] = root_a;
	}
	else
		nodes[root_a] = root_b;
}
