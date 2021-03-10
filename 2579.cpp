#include <bits/stdc++.h>

using namespace std;
int stair[301];
int d[301][3];

int main(){
	int n;
	int count = 0;
	
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> stair[i];
	}

	d[1][1] = stair[1]; d[1][2] = 0;
	d[2][1] = stair[2]; d[2][2] = stair[1] + stair[2];
	
	for(int i = 3 ; i <= n ; i ++){
		for(int j = 1 ; j <= 2 ; j ++){
			if(j == 1){ // µÎÄ­ ¶Ü
				d[i][1] = max(d[i-2][1], d[i-2][2]) + stair[i];
			}
			else{ // if j == 2 : 
				d[i][2] = d[i-1][1] + stair[i];
			}
		}
	}
	cout << max(d[n][1], d[n][2]);
	return 0;
}
