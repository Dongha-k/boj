#include <iostream>
using namespace std;
int tri[501][501];
int d[501][501];
int main(){
	int h;
	cin >> h;
	for(int i = 0 ; i < h ; i ++){
		for(int j = 0 ; j <= i ; j ++){
			cin >> tri[i][j];
		}
	}
	for(int i = 0 ; i < h ; i ++){
		d[h-1][i] = tri[h-1][i];
	}
	for(int i = h - 1 ; i >= 0 ; i --){
		for(int j = 0 ; j <= i ; j ++){
			d[i][j] = tri[i][j] + max(d[i+1][j], d[i+1][j+1]);
		}
	}
	cout << d[0][0];
	return 0;
}
