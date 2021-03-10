#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> P;
int dr[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int board[100][100];
bool check[100][100];
int w, h;
void bfs(int x, int y){
	queue<P> q;
	q.push({x, y});
	check[x][y] = true;
	while(!q.empty()){
		P cur = q.front();
		q.pop();
		for(int i = 0 ;i < 8 ; i++){
			int nx = cur.X + dr[i][0];
			int ny = cur.Y + dr[i][1];
			if(nx < 0 or nx >= h or ny < 0 or ny >= w) continue;
			if(check[nx][ny] or board[nx][ny] == 0) continue;
			check[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(true){
		cin >> w >> h;
		if(w == 0 and h == 0) break;
		for(int i = 0 ; i < h ; i ++){
			for(int j = 0 ; j < w ; j ++){
				check[i][j] = false;
				cin >> board[i][j];
			}
		}
		int cnt = 0;
		for(int i = 0 ;i < h ; i ++){
			for(int j = 0 ; j < w ; j ++){
				if(!check[i][j] and board[i][j] == 1){
					cnt ++;
					bfs(i, j);
				}
			}
		}
		cout << cnt << '\n';
	}
}
