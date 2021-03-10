#include <iostream>
#include <vector>
using namespace std;
vector<int> v[200001];
int color[200001];
bool flag = true;
void dfs(int x, int c){
	if(!flag) return;
	if(color[x] == c){
		return; // 색이 칠해져있고 인접노드와 색이 다를때 
	}
	if(color[x] != 0 and color[x] != c){ // 색이 칠해져 있는데 인접노드와 색이 다를때 
		flag = false;
		return;
	}	
	// 색이 안 칠해져 있을 때 
	color[x] = c;
	for(auto u : v[x]){
		dfs(u, 3-c);
		if(!flag) return;
	}
}
int main(){
	int t;
	cin >> t;
	int before = 1;
	while(t--){
		flag = true;
		int n, m;
		cin >> n >> m;
		for(int i = 1 ; i<= before ; i ++){
			v[i].clear(); // 인접노드 초기화 
		}
		for(int i = 0 ; i < m ; i ++){
			int x, y;
			cin >> x >> y;
			color[x] = 0;
			color[y] = 0;
			v[x].push_back(y);
			v[y].push_back(x);
			before = max(before, max(x, y));
		}
		
		for(int i = 1; i <= before ; i ++){
			if(color[i] == 0) dfs(i, 1);
			if(!flag) break;
		}
		if(!flag) cout << "NO" <<'\n';
		else cout << "YES" <<'\n';
	}
	
	return 0;
}
