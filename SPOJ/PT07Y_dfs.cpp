#include <cstdio>
#include <vector>
#include <stack>
#define MAXNODES 10001
using namespace std;

bool isGraphTree(const vector<vector<int> > &G, bool *visited){
	stack<pair<int,int> > search_stack;
	search_stack.push(pair<int,int>(0,-1));
	visited[0] = true;
	while(!search_stack.empty()){
		pair<int,int> temp = search_stack.top();
		search_stack.pop();
		for(int i=0,j=G[temp.first].size();i<j;i++){
			if(visited[G[temp.first][i]] && G[temp.first][i]==temp.second)
				continue;
			else if(visited[G[temp.first][i]] && G[temp.first][i]!=temp.second){
				return false;
			}

			else{
				visited[G[temp.first][i]] = true;
				search_stack.push(pair<int,int>(G[temp.first][i],temp.first));
			}
		}
	}
	for(unsigned int i=0;i<G.size();i++)
		if(!visited[i])
			return false;
	return true;
}

int main(){
	int N,M,u,v ;
	bool visited[MAXNODES] = {false} ;
	scanf("%d%d",&N,&M);
	vector<vector<int> > G(N);
	for(int i=0;i<N;i++){
		vector<int> temp;
		G[i] = temp;
	}
	for(int i=0;i<M;i++){
		scanf("%d%d",&u,&v);
		--u; --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	isGraphTree(G,visited) ? printf("YES\n") : printf("NO\n") ;
	return 0;
}
