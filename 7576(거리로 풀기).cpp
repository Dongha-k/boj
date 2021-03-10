#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int box[1000][1000];
int d[1000][1000];// 거리 정보 
int days;
int dr[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int m, n; // m: 높이 n:폭
typedef pair<int, int> pii;
int main(){
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++){
		for(int j = 0 ; j < n ; j ++){
			cin >> box[i][j];
		}
	}
	queue<pii> q;
	for(int i = 0 ; i < m ; i++){
		for(int j = 0; j < n ; j ++){
			if(box[i][j] == 1){
				q.push({i, j});
				d[i][j] = 0;
			}
		}
	}
	while(!q.empty()){
		pii cur = q.front(); q.pop();
		for(int i = 0 ;i < 4;  i ++){
			int nX = cur.X + dr[i][0];
			int nY = cur.Y + dr[i][1];
			if(nX < 0 or nX >= m or nY < 0 or nY >= n) continue;
			if(box[nX][nY] == 0){
				box[nX][nY] = 1;
				q.push({nX, nY});
				d[nX][nY] = d[cur.X][cur.Y] + 1;
			}
		}
	}
	for(int i = 0 ; i < m ; i ++){
		for(int j = 0 ; j < n ; j ++){
			if(box[i][j] == 0){
				cout << -1;
				return 0;
			}
			else if(box[i][j] == 1){
				days = max(days, d[i][j]);
			}
		}
	}
	cout << days;
	return 0;
}
