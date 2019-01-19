#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#define MAX 10001
using namespace std;

void longestPath(vector<vector<int> > &graph,int *distance, int source){
	pair<int,int> current;
	stack<pair<int,int> > helperstack;
	helperstack.push(pair<int,int>(source,-1));
	while(!helperstack.empty()){
		current = helperstack.top();
		helperstack.pop();
		distance[current.first] = 1+current.second;
		for(vector<int>::iterator itr = graph[current.first].begin();itr!=graph[current.first].end();++itr){
			if(distance[*itr]!=-1)
				continue;
			else{
				helperstack.push(pair<int,int>(*itr,distance[current.first]));
			}
		}
	}
}
int farthestNode(int *distance,int N){
	int farthest_node=0;
	for(int i=1;i<N;i++){
		if(distance[i]>distance[farthest_node])
			farthest_node = i ;
	}
	return farthest_node;
}

int main(){
	int distance[MAX];
	int N,u,v;
	scanf("%d",&N);
	vector<vector<int> > graph(N);
	for(int i=0;i<N-1;i++){
		scanf("%d%d",&u,&v);
		--u;--v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(distance,-1,sizeof(distance));
	longestPath(graph,distance,0);
	int farthest_node=farthestNode(distance,N);
	memset(distance,-1,sizeof(distance));
	longestPath(graph,distance,farthest_node);
	printf("%d\n",distance[farthestNode(distance,N)]);
	return 0;
}
