#include <stdio.h>
// we globally defined the visited array, and the graph
int vis[100];
int graph[100][100];

void dfs(int node, int *vis, int n){
	// mark the node as visited
	vis[node]=1;
	printf("%d ",node);
	// iterate through the row of the node
	// and check for a node that hasnt been visited, and the graph value is 1
	// graph value 1 signifies that theres a connection between those nodes
	for(int i=1;i<=n;++i){
		// this is that case
		if(vis[i]==0 && graph[node][i]==1){
			// make the recursive call
			// check connections from that node
			dfs(i,vis,n);
		}
	}
}
int main(){
	int n,e;
	// number of nodes -> n, number of edges -> e
	scanf("%d %d",&n,&e); 
	// declare the adjacency matrix
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			graph[i][j]=0;
		}
	}
	for(int i=0;i<e;++i){
		int x,y;
		// declaring the connections between the nodes
		scanf("%d %d",&x,&y);
		// u have to mark the connections in the adjcacency matrix
		graph[x][y]=1;
		graph[y][x]=1;
	}
	// mark each index of visited with 0
	for(int i=0;i<e;++i){
		vis[i]=0;
	}
	// call the first node
	dfs(1,vis,n);
	return 0;
	
	
}