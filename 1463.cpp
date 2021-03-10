#include <bits/stdc++.h>

using namespace std;


int d[1000001]; // d[i] : i를 1로 만들기 위해 필요한 연산 사용 횟수의 최솟값
int x;
	
	
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> x;
	
	d[1] = 0;
	
	for(int i = 2 ; i <= x ; i++){
		d[i] = d[i - 1] + 1;
		if(i % 2 == 0) d[i] = min(d[i / 2] + 1, d[i]); 
		if(i % 3 == 0) d[i] = min(d[i / 3] + 1, d[i]);
	}
	
	cout << d[x];	
	return 0;
}
