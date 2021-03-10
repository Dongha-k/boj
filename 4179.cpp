#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
int dr[4][2] = {{-1,0}, {1, 0}, {0, 1}, {0, -1}};
int t[1000][1000]; // 불이 도달하는데 걸리는 시간 
int d[1000][1000];
int n, m;
char canvas[1000][1000];
typedef pair<int,int> P;
int main(){
	cin >> n >> m;
	P J;
	queue<P> q;

	for(int i = 0 ; i < n ; i ++){
		for(int j =0 ; j < m ; j ++){
			cin >> canvas[i][j];
			d[i][j] = -1;
			t[i][j] = -1;
			if(canvas[i][j] == 'J'){
				J.X = i;
				J.Y = j;
			}
			else if(canvas[i][j] == 'F'){
				q.push({i, j});
				t[i][j] = 0;
				
			}
		}
	}
	while(!q.empty()){
		P cur = q.front(); q.pop();
		for(int i = 0 ; i < 4 ; i ++){
			int nX = cur.X + dr[i][0];
			int nY = cur.Y + dr[i][1];
			if(nX < 0 or nX >= n or nY < 0 or nY >= m) continue;
			if(canvas[nX][nY] != '#' and t[nX][nY] < 0){
				t[nX][nY] = 1 + t[cur.X][cur.Y];
				q.push({nX, nY});
			}
		}
	}
//	for(int i = 0 ; i < n ; i ++){
//		for(int j = 0;j < m ; j ++){
//			if(canvas[i][j] != '#') cout << t[i][j] << ' ';
//			else cout << canvas[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	q.push(J);
	d[J.X][J.Y] = 0;
	while(!q.empty()){
		P cur = q.front(); q.pop();
		for(int i = 0 ; i < 4 ; i ++){
			int nX = cur.X + dr[i][0];
			int nY = cur.Y + dr[i][1];
			if(nX < 0 or nX >= n or nY < 0 or nY >= m){ // 탈출완료 
				cout << d[cur.X][cur.Y] + 1;
				return 0;
			}
			if(canvas[nX][nY] == '#') continue;
			if(d[nX][nY] >= 0) continue; // 이미 방문한 위치일시 컨티뉴
			if(t[nX][nY] != -1 and t[nX][nY] <= 1 + d[cur.X][cur.Y]) continue; // 불이 도달하지 않은 곳이 아니고 불의 도달시간이 더 짧으면 컨티뉴 
			d[nX][nY] = 1 + d[cur.X][cur.Y];
			q.push({nX, nY});
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}
