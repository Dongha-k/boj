#include <iostream>
using namespace std;
int board[1000][1000];
int d[1000][1000];
int dr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
bool visited[1000][1000];
int _min = 100000000;
bool used = false;
void dfs(int x, int y){
	if(visited[x][y]) return;
	visited[x][y] = true;
	if(board[x][y] == 1) used = true;
	for(int i = 0 ; i < 4 ; i ++){
		int nx = x + dr[i][0];
		int ny = y + dr[i][1];
		if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
		if(visited[nx][ny]) continue;
		if(board[nx][ny] == 1 and used) continue;
		d[nx][ny] = d[x][y] + 1;
		if(nx == n-1 and ny == m-1) _min = min(_min, d[nx][ny]);
		dfs(nx, ny);
		if(board[nx][ny] == 1) used = false;
		visited[nx][ny] = false;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0 ; i < n ;i ++){
		for(int j = 0 ; j < m ; j ++){
			d[i][j] = 0;
			visited[i][j] = false;
			char ch;
			cin >> ch;
			board[i][j] = ch-'0';
		}
	}
	d[0][0] = 1;
	dfs(0, 0);
	if(d[n-1][m-1] == 0) cout << -1;
	else cout << _min;
	return 0;
}
