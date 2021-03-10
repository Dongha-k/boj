#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int height, width; // ����, �ʺ�
int canvas[500][500];
int dir[4][2] = { // ������ �� �ִ� ���� 
	{0,1},
	{-1, 0},
	{0, -1},
	{1,0}
};
bool visited[500][500] = {false, }; // �湮 ���� 
int max_size = 0; // �ִ� ũ�� 
int numOfPicture = 0; // �׸��� ���� 
typedef pair<int, int> pii;
int searchUsingBFS(int x, int y){
	int cnt = 0;
	queue<pii> q; // bfs�� ����� ť ���� 
	q.push({x, y});
	visited[x][y] = true;
	cnt ++;
	while(!q.empty()){
		pii cur = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i ++){
			int next_x = cur.X + dir[i][0];
			int next_y = cur.Y + dir[i][1];
			if(next_x < 0 or next_x >= height) continue;
			if(next_y < 0 or next_y >= width) continue;
			if(!visited[next_x][next_y] && canvas[next_x][next_y] == 1){ // �湮���� ���� ��� �湮 
				visited[next_x][next_y] = true;
				q.push({next_x, next_y});
				cnt ++;
			}
		}
	}
	return cnt;
}
int main(){
	cin >> height >> width;
	for(int i = 0 ; i < height ; i ++){
		for(int j = 0 ; j < width ; j ++){
			cin >> canvas[i][j];
		}
	}
	int area; 
	for(int i = 0 ; i < height ; i ++){
		for(int j = 0 ; j < width ; j ++){
			if(!visited[i][j] && canvas[i][j] == 1){
				//1�ε� �湮���� ���� ���
				numOfPicture ++;
				area = searchUsingBFS(i, j);
				max_size = (max_size < area)? area : max_size;
			}
		}
	}
	cout << numOfPicture << '\n' << max_size;
	return 0;
}
