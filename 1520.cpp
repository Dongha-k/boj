#include <iostream>
using namespace std;
int board[500][500];
int d[500][500];
int dr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
bool check[500][500];
void dfs(int x, int y){
	if(d[x][y] != 0) return;
	for(int i = 0 ;i < 4 ; i ++){
		int nx = x + dr[i][0];
		int ny = y + dr[i][1];
		if(nx < 0 or nx >= n  or ny < 0 or ny >= m) continue;
		if(board[x][y] <= board[nx][ny]) continue;
		if(check[nx][ny]) continue;
		check[nx][ny] = true;
		dfs(nx, ny);
		check[nx][ny] = false;
		d[x][y] += d[nx][ny];
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			d[i][j] = 0;
			check[i][j] = false;
			cin >> board[i][j];
		}
	}
	d[n-1][m-1] = 1;
	dfs(0, 0);
	cout << d[0][0];
	return 0;
}
