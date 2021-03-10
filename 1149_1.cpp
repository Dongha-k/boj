#include <bits/stdc++.h>

using namespace std;

int house[1001][3]; // 칠할 색의 비용
int m = 100000000, n;
int selected[1001];
int temp;

void f(int k){
	if(k == n){
		temp = 0;
		
		for(int i = 0 ; i < n ; i ++){
			temp += house[i][selected[i]];
		}
		m = min(m, temp);
	}
	else{
		for(int i = 0 ; i < 3 ; i ++){
			if(k == 0 or selected[k-1] != i){
				
				selected[k] = i;
				f(k+1);
			}
		}
	}
	
}

int main(){
	cin >> n;
	
	for(int i = 0 ; i < n ; i ++){
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}
	
	f(0);
	cout << m;
	return 0;
}
