#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
vector<int> v;
int n, m;
int dr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int rect[101][101];
typedef pair<int, int> pii;

int bfs(int x, int y){
	int cnt = 0;
	queue<pii> q;
	q.push({x, y});
	rect[x][y] = 1;
	while(!q.empty()){
		pii cur = q.front();
		cnt ++;
		q.pop();
		for(int i = 0 ; i < 4 ; i ++){
			int nX = cur.X + dr[i][0];
			int nY = cur.Y + dr[i][1];
			if(nX < 0 or nX >= n or nY < 0 or nY >= m) continue;
			if(rect[nX][nY] == 1) continue;
			rect[nX][nY] = 1;
			q.push({nX, nY});
		}
	}
	return cnt;
}
int main(){
	int k;
	cin >> n >> m >> k;
	for(int i = 0 ; i < k ; i ++){
		int fX, fY, eX, eY;
		cin >> fX >> fY >> eX >> eY;
		for(int i = fY ; i < eY ; i ++){
			for(int j = fX ; j < eX ; j ++){
				rect[i][j] = 1;
			}
		}
	}
	
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < m ; j ++){
			if(rect[i][j] == 0){
				v.push_back(bfs(i,j));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() <<'\n';
	for(auto u : v){
		cout << u << ' ';
	}
	return 0;
}
