#include <iostream>
using namespace std;
int coin[10001];
int d[100001] = {};
int n, x; // 동전의 갯수, 가격의 합
int solve(int x){
	int _min = 1000001;
	if(d[x] != 0) return d[x];
	for(int i = 0 ; i < n ; i ++){
		if(x - coin[i] <= 0) continue; // 인덱스가 0보다 같거나 작으면 무시 
		if(d[x-coin[i]] == 0) d[x-coin[i]] = solve(x-coin[i]);
		int y = d[x-coin[i]] + 1;
		if(_min >= y){
			_min = y;
		}
	}
	return d[x] = _min;
}
int main(){
	cin >> n >> x;
	for(int i = 0 ; i < n ; i ++){
		cin >> coin[i]; // 동전의 가격 입력
		d[coin[i]] = 1;
	}
	int answer = solve(x);
	if(answer == 1000001){
		cout << -1;
	}
	else{
		cout <<answer;
	}
	return 0;
}
