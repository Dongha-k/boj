#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int board[50][50];
int m, n, k;
int dr[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool visited[50][50];
void bfs(int x, int y){
	queue<pii> q;
	q.push({x, y});
	visited[x][y] = true;
	while(!q.empty()){
		pii cur = q.front(); q.pop();
		for(int i = 0 ; i < 4 ; i ++){
			int nX = cur.X + dr[i][0];
			int nY = cur.Y + dr[i][1];
			if(nX < 0 or nX >= n or nY < 0 or nY >= m) continue;
			if(visited[nX][nY] or board[nX][nY] == 0) continue;
			visited[nX][nY] = true;
			q.push({nX, nY});
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i = 0 ; i < 50 ; i ++){
			fill(board[i], board[i] + 50, 0);
			fill(visited[i], visited[i] + 50, false);
		}
		cin >> n >> m >> k;
		while(k--){
			int x, y;
			cin >> x >> y;
			board[x][y] = 1;
		}
		int cnt = 0;
		for(int i = 0 ; i < n ; i ++){
			for(int j = 0 ; j < m ; j ++){
				if(board[i][j] == 1 and !visited[i][j]){
					bfs(i, j);
					cnt ++;
				}
			}
		}
		cout<< cnt << '\n';
	}
	return 0;
}
