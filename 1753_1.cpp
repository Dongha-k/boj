#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000
#define MAX 200001
#define W first
#define To second
using namespace std;
typedef pair<int, int> pii;
vector<pii> adj[MAX];
int d[MAX];
bool v[MAX];
int main(){
	int n, m, start;
	cin >> n >> m;
	cin >> start;
	for(int i = 0 ; i < m ; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}
	priority_queue<pii> pq;
	
	
	return 0;
}
