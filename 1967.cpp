#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> P;
int n, depth = 0;
int max_depth_i = 0;
int max_depth_v = 0;

vector<P> adj[100001];
void dfs(int s, int e){
	if(max_depth_v < depth){
		max_depth_i = s;
		max_depth_v = depth;
	}
	
	for(P u : adj[s]){
		if(u.first != e){
			depth += u.second;
			dfs(u.first, s);
			depth -= u.second;
		}
	}
}
int main(){
	cin >> n;
	int t = n-1;
	while(t--){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
		
	}
	dfs(1, 0);
	int node = max_depth_i;
	max_depth_v = 0;
	max_depth_i = 0;
	dfs(node, 0);
	cout << max_depth_v;
	return 0;
}
