#include <bits/stdc++.h>

using namespace std;
int n;
bool isUsed1[50]; // 세로 방향 
bool isUsed2[50]; // 대각선 방향 
bool isUsed3[50]; // 역대각선 방향 

int queen[15][15];
int cnt = 0;

void bs(int k){ // k = k번쨰 줄
	if(k == n){	
		cnt++;
		return;
	}
	for(int i = 0 ; i < n ; i ++){
		// 좌표 : (k, i) 
		if(isUsed1[i] && isUsed2[i-k+n-1] && isUsed3[i+k]){ // (i, k) 자리에 놓을 수 있을 때 셋다 true 반환
			isUsed1[i] = false;
			isUsed2[i-k+n-1] = false;
			isUsed3[i+k] = false;
			bs(k+1);
			isUsed1[i] = true;
			isUsed2[i-k+n-1] = true;
			isUsed3[i+k] = true;
		} 
	} 
}

int main(){
	cin >> n;
	for(int i = 0 ;i < 2*n-1; i ++){
		isUsed1[i] = true;
		isUsed2[i] = true;
		isUsed3[i] = true;
	}
	bs(0);
	cout << cnt;
	return 0;
}
