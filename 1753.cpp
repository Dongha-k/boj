#include <iostream>
#include <vector>
#include <queue>
#define W first
#define To second
#define INF 1000000
using namespace std;
typedef pair<int, int> pii;
vector<pii> adj[200001];
bool visited[200001] = {false, };
int d[200001];
int e, v;
int start;
int main(){
	cin >> v >> e;
	cin >> start;
	for(int i = 0 ;i < e ; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}
	fill(d, d + 200001, INF);
	priority_queue<pii> pq;
	pq.push({0, start});
	d[start] = 0;
	while(!pq.empty()){
		int cur = pq.top().To;
		pq.pop();
		if(visited[cur]) continue; // 이미처리된 노드면 continue 
		visited[cur] = true; // 뺄 떄 방문처리 
		for(auto u : adj[cur]){
			d[u.To] = min(d[u.To], d[cur] + u.W);
			pq.push({-d[u.To], u.To});
		}
	}
	for(int i = 1 ; i <= v ; i ++){
		if(d[i] == INF) cout << "INF\n";
		else cout << d[i]<< '\n';
	}
	return 0;
}
