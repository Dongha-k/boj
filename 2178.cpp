#include <iostream>
#include <queue>
#define X first
#define Y second
#define INF 100000
using namespace std;
typedef pair<int, int> P;
int dr[4][2]={{-1, 0},{1, 0},{0, -1},{0, 1}};
int width, height;   // ��, ����
int maze[100][100]; // �̷�
bool visited[100][100];// �湮���� 
int d[100][100];  // ��������κ����� �ִܰŸ�
void bfs(int x, int y){
	queue<P> q;
	d[x][y] = 1;
	q.push({x,y});
	while(!q.empty()){
		P cur = q.front(); q.pop();
		for(int i = 0 ; i < 4 ; i ++){ // ���� ���� 
			int nextX = cur.X + dr[i][0];
			int nextY = cur.Y + dr[i][1];
			if(nextX < 0 or nextX >= height) continue;
			if(nextY < 0 or nextY >= width) continue;
			if(maze[nextX][nextY] != 1) continue;
			d[nextX][nextY] = min(d[nextX][nextY], d[cur.X][cur.Y]+1);
			if(!visited[nextX][nextY]){
				q.push({nextX, nextY});
				visited[nextX][nextY] = true;
			}
		}
	}
}
int main(){
	char _line[101];
	cin >> height >> width;
	for(int i = 0 ; i < height ; i ++){
		cin >> _line;
		for(int j = width - 1 ; j >= 0 ; j --){
			maze[i][j] = _line[j] - '0';
			d[i][j] = INF;
			visited[i][j] = false;
		}
	}
	bfs(0,0);
	cout << d[height-1][width-1];
	return 0;
}
