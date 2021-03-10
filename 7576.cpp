#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> P;
int dr[4][2]={{-1, 0},{1, 0},{0, -1},{0, 1}};
int width, height;   // 폭, 높이
int box[1000][1000]; // 토마토 칸
int days = 0;
void showState(){
		cout << '\n' << days << ".. " << '\n';
	for(int i= 0 ; i < height ; i++){
		for(int j = 0 ;j < width ; j ++){
			cout << box[i][j];
		}
		cout << '\n';
	}
}
int bfs(){
	queue<P> q[2]; // q[1] : 임시큐 
	for(int i = 0 ; i < height ; i ++){
		for(int j = 0 ; j < width ; j ++){
			if(box[i][j] == 1){
				q[0].push({i, j});
			}
		}
	}
	if(q[0].empty()){
		return -1; // 익은 토마토가 하나도 없을 시 -1 반환 
	}
	while(!q[0].empty() or !q[1].empty()){
		while(!q[0].empty()){
			P cur = q[0].front(); q[0].pop();
			for(int i = 0 ; i < 4 ; i ++){
				int nX = cur.X + dr[i][0];
				int nY = cur.Y + dr[i][1];
				if(nX < 0 or nX >= height or nY < 0 or nY >= width) continue;
				if(box[nX][nY] == 0){
					q[1].push({nX, nY});
					box[nX][nY] = 1;
				}
			}
		}
		while(!q[1].empty()){
			q[0].push(q[1].front());
			q[1].pop();
		}
		days++;
	}
	for(int i = 0 ; i < height ; i ++){
		for(int j =0 ; j < width ; j ++){
			if(box[i][j] == 0){
				return -1;
			}
		}
	}
	return days - 1;
}

int main(){
	P start;
	cin >> width >> height;
	for(int i = 0 ; i < height ; i++){
		for(int j = 0; j < width ; j ++){
			cin >> box[i][j];
		}
	}

	cout << bfs();
	return 0;
} 
