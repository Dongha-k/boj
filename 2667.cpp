#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int, int > pii;
int n;
int dr[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int board[30][30];
bool visited[30][30];
int bfs(int x, int y){
	int cnt = 0;
	queue<pii> q;
	q.push({x, y});
	visited[x][y] = true;
	while(!q.empty()){
		pii cur = q.front();
		cnt ++;
		q.pop();
		for(int i = 0 ; i< 4 ; i ++){
			int nX = cur.X + dr[i][0];
			int nY = cur.Y + dr[i][1];
			if(nX < 0 or nX >= n or nY < 0 or nY >= n) continue;
			if(visited[nX][nY]) continue;
			if(board[nX][nY] == 0) continue;
			if(!visited[nX][nY]){
				visited[nX][nY] = true;
				q.push({nX, nY});
			}
		}
	}
	return cnt;
}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		char c;
		for(int j = 0 ; j < n ; j ++){
			cin >> c;
			board[i][j] = c - '0';
		}
	}
	vector<int> result;
	for(int i =0  ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++){
			if(!visited[i][j] && board[i][j] == 1){
				result.push_back(bfs(i, j));
			}
		}
	}
	cout << result.size() << '\n';
	sort(result.begin(), result.end());
	for(auto i : result){
		cout << i << '\n';
	}
	return 0;
}
