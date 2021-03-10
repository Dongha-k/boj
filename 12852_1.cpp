#include <bits/stdc++.h>
using namespace std;

int d[1000001]; // d[i]: i에서 1로 만드는 횟수의 최솟값
int pre[1000001]; // 경로 복원용 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x;
	
	cin >> x;
	
	d[1] = 0;
	pre[1] = 0;
	for(int i = 2; i <= x ; i ++){
		
		d[i] = d[i-1] + 1;
		pre[i] = i - 1;
		
		if(i % 2 == 0){
			if(d[i/2] + 1 < d[i]){
				d[i] = d[i/2] + 1;
				pre[i] = i/2;
			}
		}
		
		if(i % 3 == 0){
			if(d[i/3] + 1 < d[i]){
				d[i] = d[i/3] + 1;
				pre[i] = i/3;
			}
		}
	}
	
	cout << d[x] << '\n';
//	
//	cout << x << ' ';
//	for(int i = x ; i > 1 ; i = pre[i]){
//		cout << pre[i] << ' ';
//	}


	int y = x;
	while(true){
		if(y == 1){
			cout << 1; 
			break;
		}
		cout << y << ' ';
		y = pre[y]; // 다음 숫자로 넘어감 
	}
	
	
	return 0;
}
