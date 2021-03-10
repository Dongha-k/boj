#include <bits/stdc++.h>

using namespace std;

int house[1001][3]; // 칠할 색의 비용
int d[1001][3];

int main(){
	int n;	cin >> n;
	
	for(int i = 1 ; i <= n ; i ++){
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}
	d[1][0] = house[1][0];
	d[1][1] = house[1][1];
	d[1][2] = house[1][2];
	
	for(int i = 2 ; i <= n ; i ++){
		for(int j = 0 ; j < 3 ; j ++){
			d[i][j] = min(d[i-1][(j+1)%3], d[i-1][(j+2)%3]) + house[i][j];
		}
	}
	cout << min(d[n][0], min(d[n][1], d[n][2]));
	
	return 0;
}
