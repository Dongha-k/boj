#include <iostream>
#include <vector>
using namespace std;
vector<int> v[1001];
bool check[1001] = {false, };
int n, m;
void dfs(int s){
	check[s] = true;
	for(auto u : v[s]){
		if(!check[u]){
			dfs(u);
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0 ; i < m ;  i ++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(!check[i]){
			dfs(i);
			cnt ++;
		}
	}
	cout << cnt;
	return 0;
}
