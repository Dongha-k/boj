#include <iostream>
using namespace std;
int arr[10000];
int d[10001][3];
int main(){
	int t; cin >> t;
	for(int i = 1 ; i <= t ; i++){
		int x; cin >> x;
		arr[i] = x;
	}
	d[0][1] = 0; d[0][2] = 0;
	d[1][1] = arr[1]; d[1][2] = 0;
	for(int i = 2 ; i <= t; i ++){
		d[i][1] = arr[i] + max(d[i-2][1], d[i-2][2]);
		d[i][2] = arr[i] + d[i-1][1];
	}
	d[t+1][1] = max(d[t-1][1], d[t-1][2]);
	d[t+1][2] = max(d[t][1], d[t][2]);
	cout << max(d[t+1][1], d[t+1][2]); 
	return 0;
	}
