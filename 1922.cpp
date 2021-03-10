#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
vector<tuple<int,int,int>> v;
int link[1001];
int find(int x){
	while(x != link[x]) x = link[x];
	return x;
}
bool same(int x, int y){
	return find(x) == find(y);
}
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x>y) link[x] = y;
	else link[y] = x;
}
int main(){
	int n; // 컴퓨터의 갯수
	int m; // 연결할 수 있는 선의 갯수
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		link[i] = i;
	}
	for(int i = 0 ; i < m ; i ++){
		int x, y, w;
		cin >> x >> y >> w;
		v.push_back(make_tuple(w, x, y)); // 간선 정보 입력 
	}
	int spare = 0;
	sort(v.begin(), v.end());
	for(auto u : v){
		int w, x, y;
		tie(w, x, y) = u;
		if(!same(x, y)){ // 사이클이 발생하지 않는다면
			unite(x, y); // 연결 
			spare += w;
		}
	}
	cout << spare;
	return 0;
}
