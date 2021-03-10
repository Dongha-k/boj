#include <bits/stdc++.h>
using namespace std;

int d[1000001]; // d[i]: i에서 1로 만드는 횟수의 최솟값 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x;
	
	cin >> x;
	
	d[1] = 0;
	for(int i = 2; i <= x ; i ++){
		
		d[i] = d[i-1] + 1;
		if(i % 2 == 0) d[i] = min(d[i/2] + 1, d[i]);
		if(i % 3 == 0) d[i] = min(d[i/3] + 1, d[i]);
	}
	cout << d[x] << '\n';
	int y = x; // 현재 위치한 숫자(역추적) 
	
	while(1){
		if(y == 1){
			cout << y;
			break;
		}
		else{
			if(y % 3 == 0 and d[y] == 1 + d[y/3]){
				cout << y << ' ';
				y/=3;
			}
			else if(y % 2 == 0 and d[y] == 1 + d[y/2]){
				cout << y << ' ';
				y/=2;
			}
			else{
				cout << y << ' ';
				y--;
			}
		}
	}
	
	return 0;
}
