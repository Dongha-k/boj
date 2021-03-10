#include <iostream>
#define mod 1000000000
using namespace std;
long long d[101][10];
long long sum = 0;
int main(){
	int x; cin >> x;
	if(x == 1){
		cout << 9;
		return 0;
	}
	d[1][0] = 0 ; d[1][1] = 1 ; d[1][2] = 1; d[1][3] = 1;
	d[1][4] = 1 ; d[1][5] = 1 ; d[1][6] = 1; d[1][7] = 1;
	d[1][8] = 1 ; d[1][9] = 1 ;
	
	for(int i = 2; i <= x ; i ++){
		for(int j = 2 ; j <= 8 ; j ++){
			d[i][j] = d[i-1][j-1] % mod + d[i-1][j+1] % mod;
		}
		d[i][0] = d[i-1][1] % mod;
		d[i][1] = d[i-1][2] % mod+ d[i-1][0] % mod;
		d[i][9] = d[i-1][8] % mod;
	}
	
	for(int i = 0 ; i < 10 ; i ++){
		sum += d[x][i] % mod;
	}
	cout << sum % mod;
	return 0;
}
