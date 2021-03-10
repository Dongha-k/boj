#include <iostream>
using namespace std;
typedef long long ll;
ll path[200000];
ll price[200000];
int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n -1 ; i ++){
		cin >> path[i]; // 도시 간 거리 
	}
	for(int i = 0 ; i < n ; i ++){
		cin >> price[i]; 
	}
	ll _min = price[0];
	ll total = 0;
	for(int i = 0 ; i < n - 1; i ++){
		_min = min(price[i], _min);
		total += path[i] * _min;
	}
	cout << total;
	return 0;
}
