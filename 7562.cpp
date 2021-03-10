#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int dr[8][2] = {{-2,1},{-2,-1},{-1,-2},{-1,2}
				,{2,1},{2,-1},{1,-2},{1,2}};
typedef pair<int, int> pii;
int d[300][300];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		int cnt = 0;
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			fill(d[i], d[i]+n, -1);
		}
		int startX, startY;
		cin >> startX >> startY;
		int endX, endY;
		cin >> endX >> endY;
		queue<pii> q;
		q.push({startX, startY});
		d[startX][startY] = 0;
		while(!q.empty()){
			pii cur = q.front();
			if(cur.X == endX and cur.Y == endY){
				cout << d[cur.X][cur.Y] << '\n';
				break;
			}
			q.pop();
			for(int i = 0 ; i < 8 ; i ++){
				int nX = cur.X + dr[i][0];
				int nY = cur.Y + dr[i][1];
				if(nX < 0 or nX >= n or nY < 0 or nY >= n) continue;
				if(d[nX][nY] >= 0) continue;
				d[nX][nY] = d[cur.X][cur.Y] + 1;
				q.push({nX, nY});
			}
		}
	}
	return 0;
}
