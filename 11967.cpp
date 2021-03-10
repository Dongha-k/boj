#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int visited[101][101];
vector<pii> adj[101][101];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		fill(visited[i], visited[i]+n, false);
	}
	for(int i = 0 ; i < m ; i ++){
		int bX, bY, eX, eY;
		cin >> bX >> bY >> eX >> eY;
		adj[bX][bY].push_back({eX, eY});
		adj[eX][eY].push_back({bX, bY});
	}
	int cnt = 0;	
	queue<pii> q;
	q.push({1, 1});
	visited[1][1] = true;
	while(!q.empty()){
		pii cur = q.front();
 		q.pop();
		cnt ++;
		for(auto u : adj[cur.X][cur.Y]){
			if(!visited[u.X][u.Y]){
				visited[u.X][u.Y] = true;
				q.push({u.X, u.Y});
			}
		}
	}
	cout << cnt;
	return 0;
}
