#include <cstdio>
#define MAXNODES 10001
#define MAXEDGES 2*MAXNODES

int findroot(int i, int *Nodes){
	int temp = i, current_parent, root;
	while(temp != Nodes[temp]){
		temp = Nodes[temp] ;
	}
	root = temp;
	temp = i;
	while(temp != Nodes[temp]){
		current_parent = Nodes[temp];
		Nodes[temp] = root;
		temp = current_parent;
	}
	return root;
}

bool isConnected(int a, int b, int *Nodes){
	return findroot(a,Nodes) == findroot(b,Nodes);
}

void Union(int a,int b, int *Nodes, int *rank){
	int root_a = findroot(a,Nodes);
	int root_b = findroot(b,Nodes);
	if(rank[root_a] >= rank[root_b]){
		rank[root_a] = rank[root_a]== rank[root_b] ? rank[root_a] + 1 : rank[root_a];
		Nodes[root_b] = root_a;
	}
	else{
		Nodes[root_a] = root_b;
	}
}

bool isTree(int *Nodes,int *rank,int N, int *u, int *v, int M){
	for(register int i=0;i < M; i++){
		if(isConnected(u[i],v[i],Nodes))
			return false;
		else 
			Union(u[i],v[i],Nodes,rank);
	}
	int global_root = findroot(0,Nodes);
	for(register int i=1;i<N;i++)
		if(findroot(i,Nodes)!=global_root)
			return false;
	return true;
}

int main(){
	int Nodes[MAXNODES],rank[MAXNODES]={0},u[MAXEDGES],v[MAXEDGES];
	int N,M;
	scanf("%d%d",&N,&M);
	for(register int i=0;i<N;i++)
		Nodes[i]=i;
	for(register int i=0;i<M;i++){
		scanf("%d%d",u+i,v+i);
		(*(u+i))--;
		(*(v+i))--;
	}
	isTree(Nodes,rank,N,u,v,M) ? printf("YES\n") : printf("NO\n");
	return 0;
}
