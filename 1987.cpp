#include <iostream>
#define first X
#define second Y
using namespace std;
typedef pair<int, int> p;
bool v[30][30];
int d[30][30];
char board[30][30];
int r, c;
int _max = 1;
bool check[26] = {false, };
int dr[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
void dfs(int x, int y){
	check[board[x][y]-'A'] = true;
	for(int i = 0 ; i < 4 ; i++){
		int nx = x + dr[i][0];
		int ny = y + dr[i][1];
		if(nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
		if(check[board[nx][ny]-'A']) continue;
		d[nx][ny] = d[x][y] + 1;
		_max = max(_max, d[nx][ny]);
		dfs(nx, ny);
		check[board[nx][ny]-'A']  = false;
	}
}
int main(){
	cin >> r >> c;
	for(int i = 0 ; i < r ; i ++){
		for(int j = 0 ; j < c; j ++){
			d[i][j] = 0;
			v[i][j] = false;
			cin >> board[i][j];
		}
	}
	d[0][0] = 1;
	dfs(0, 0);
	cout << _max;
	return 0;
}
