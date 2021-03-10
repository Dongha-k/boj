#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> Ti;
vector<Ti> v;
int link[10001];
int find(int x){
	while(x!=link[x]) x = link[x];
	return x;
}
bool same(int x, int y){
	return find(x) == find(y);
}
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x > y){ // y가 x쪽에 붙어야함 
		link[y] = x;
	}
	else{
		link[x] = y;
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		link[i] = i;
	}
	for(int i = 0 ; i < m ; i++){
		int w, a, b;
		cin >> a >> b >> w;
		v.push_back(make_tuple(w, a, b));
	}
	sort(v.begin(), v.end());
	long long answer = 0;
	for(auto u : v){
		int w, a, b;
		tie(w, a, b) = u;
		if(!same(a, b)) {
			unite(a, b);
			answer += w;
		}
	}
	cout << answer;
	return 0;
}
