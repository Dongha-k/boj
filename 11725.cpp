#include <iostream>
using namespace std;
int link[1000001];
int find(int x){
	while(x!=link[x]) x = link[x];
	return x;
}
void uni(int x, int y){
	int parentX = find(x);
	int parentY = find(y);
	if(parentY > parentX){
		link[y] = x;
	}
	else{
		link[x] = y;
	}
}
bool same(int x, int y){
	return find(x) == find(y);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		link[i] = i;
	}
	for(int i = 0 ; i < n -1 ;i ++){
		int x, y;
		cin >> x >> y;
		uni(x, y);
	}
	for(int i = 2 ;i <= n ; i ++){
		cout << link[i] <<'\n';
	}
	return 0;
}
