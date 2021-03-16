#include <iostream>
#include <queue>
#include <vector>
#define w first // ������ 
#define to second // ����ġ
#define INF 100000000
using namespace std;
typedef pair<int, int> P;
int d[1001];
vector<P> adj[1001]; 
int main(){
	int n;// ������ ����  =  ����� ���� 
	int m; // ������ ���� = ������ ����
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
				d[to] = distance + d[cur]; //�ּҰ�� �� ���� 
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
