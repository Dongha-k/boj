#include <bits/stdc++.h>

using namespace std;
int n;
bool isUsed1[50]; // ���� ���� 
bool isUsed2[50]; // �밢�� ���� 
bool isUsed3[50]; // ���밢�� ���� 

int queen[15][15];
int cnt = 0;

void bs(int k){ // k = k���� ��
	if(k == n){	
		cnt++;
		return;
	}
	for(int i = 0 ; i < n ; i ++){
		// ��ǥ : (k, i) 
		if(isUsed1[i] && isUsed2[i-k+n-1] && isUsed3[i+k]){ // (i, k) �ڸ��� ���� �� ���� �� �´� true ��ȯ
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
