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
	int n; // ��ǻ���� ����
	int m; // ������ �� �ִ� ���� ����
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		link[i] = i;
	}
	for(int i = 0 ; i < m ; i ++){
		int x, y, w;
		cin >> x >> y >> w;
		v.push_back(make_tuple(w, x, y)); // ���� ���� �Է� 
	}
	int spare = 0;
	sort(v.begin(), v.end());
	for(auto u : v){
		int w, x, y;
		tie(w, x, y) = u;
		if(!same(x, y)){ // ����Ŭ�� �߻����� �ʴ´ٸ�
			unite(x, y); // ���� 
			spare += w;
		}
	}
	cout << spare;
	return 0;
}
