#include <iostream>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> P;
int dr[6][3]={
{-1, 0, 0},{1, 0, 0},{0, -1, 0},{0, 1, 0}
,{0, 0, 1},{0, 0, -1}};

int width, height, floor;   // 폭, 높이, 층수; 
int box[100][100][100]; // 토마토 칸
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
	
	queue<tuple<int, int, int>> q[2]; // q[1] : 임시큐 
	for(int k = 0; k < floor ; k ++){
		for(int i = 0 ; i < height ; i ++){
			for(int j = 0 ; j < width ; j ++){
				if(box[i][j][k] == 1){
					q[0].push(make_tuple(i, j, k));
				}
			}
		}
	}
	if(q[0].empty()){
		return -1; // 익은 토마토가 하나도 없을 시 -1 반환 
	}
	while(!q[0].empty() or !q[1].empty()){
		while(!q[0].empty()){
			int curX, curY, curZ;
			tie(curX, curY, curZ) = q[0].front();
			q[0].pop();
			for(int i = 0 ; i < 6 ; i ++){
				int nX = curX + dr[i][0];
				int nY = curY + dr[i][1];
				int nZ = curZ + dr[i][2];
				if(nX < 0 or nX >= height or nY < 0 or nY >= width) continue;
				if(nZ < 0 or nZ >= floor) continue;
				if(box[nX][nY][nZ] == 0){
					q[1].push(make_tuple(nX, nY, nZ));
					box[nX][nY][nZ] = 1;
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
			for(int k = 0 ; k < floor ;k ++){
				if(box[i][j][k] == 0){
				return -1;
				}
			}
		}
	}
	return days - 1;
}

int main(){
	P start;
	cin >> width >> height >> floor;
	for(int k = 0 ; k < floor ; k ++){
		for(int i = 0 ; i < height ; i++){
			for(int j = 0; j < width ; j ++){
				cin >> box[i][j][k];
			}
		}
	}

	cout << bfs();
	return 0;
} 
