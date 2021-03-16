#include <iostream>
#include <queue>
#include <vector>
#define w first // 도착지 
#define to second // 가중치
#define INF 100000000
using namespace std;
typedef pair<int, int> P;
int d[1001];
vector<P> adj[1001]; 
int main(){
	int n;// 도시의 갯수  =  노드의 갯수 
	int m; // 버스의 갯수 = 간선의 갯수
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++){
		int from, to, w;
		cin >> from >> to >> w;
		adj[from].push_back({w, to});
	}
	int first, end;
	cin >> first >> end;
	priority_queue<P> pq;
	for(int i = 1 ; i <= n ; i ++){
		d[i] = INF;
	}
	d[first] = 0;
	pq.push({0, first});
	while(!pq.empty()){
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if(dist > d[cur]) continue;
		for(auto u : adj[cur]){
			int distance = u.w;
			int to = u.to;
			if(d[to] > distance + d[cur]){
				d[to] = distance + d[cur]; //최소경로 값 갱신 
				pq.push({-d[to],to}); 
			}
		}
	}
	cout << d[end];
//	for(int i=1 ; i<=n ;i ++){
//		cout << d[i] << '\n';
//	}
	return 0;
}
