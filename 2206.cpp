#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int board[1000][1000];
int visit[1000][1000][2];
int dr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0 ; i < n ;i ++){
		for(int j = 0 ; j < m ; j ++){
			visit[i][j][0] = 0;
			visit[i][j][1] = 0;
			char ch;
			cin >> ch;
			board[i][j] = ch-'0';
		}
	}
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(0,0,0));
	visit[0][0][0] = 1;
	while(!q.empty()){
		int curX, curY, curV;
		tie(curX, curY, curV) = q.front();
		q.pop();
		if(curX == n - 1 and curY == m - 1){
			cout << visit[curX][curY][curV];
			return 0;
		}
		for(int i = 0 ; i < 4 ; i ++){
			int nx = curX + dr[i][0];
			int ny = curY + dr[i][1];
			if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue; // ��踦 ��� 
			if(visit[nx][ny][curV] > 0) continue;
			if(board[nx][ny] == 1 and curV == 1) continue; // ������ ���� �ν��µ� �� ���� ����
			if(board[nx][ny] == 1 and curV == 0){ // ���� �μ� ���� ���µ� �̹��� ���� ó�� ���� ��� curV == 0
				visit[nx][ny][1] = visit[curX][curY][curV] + 1;
				q.push(make_tuple(nx, ny, 1)); 
			}
			else if(board[nx][ny] == 0 and curV == 0){ // ���� �μ����� ���� �̹����� ���� �ƴѰ�� 
				visit[nx][ny][curV] = visit[curX][curY][curV] + 1;
				q.push(make_tuple(nx, ny, curV));
			}
			else{ // ���� �μ����� ������ �ְ� �̹����� ���� �ƴ� ��� curV == 1 �̰� board[nx][ny] == 0 
				visit[nx][ny][curV] = visit[curX][curY][curV] + 1;
				q.push(make_tuple(nx, ny, curV));
			}
		}
	}
//	for(int i=0; i<n; i ++){
//		for(int j = 0 ;j < m ; j ++){
//			cout << d[i][j] << '\t';
//		}cout << endl;
//	}
//	if(d[n-1][m-1] == 0) cout << -1;
//	else cout << d[n-1][m-1];
	cout << -1;
	return 0;
}


/*
8 8
01000100
01010100
01010100
01010100
01010100
01010100
01010100
00010100

6 4
0100
1110
1000
0000
0111
0000

4 4
0111
1111
1111
1110
*/
