#include <iostream>
using namespace std;
int d[1000][10]; 
int main(){
	int n;
	cin >> n;
	d[1][0] = 1; d[1][1] = 1; d[1][2] = 1;
	d[1][3] = 1; d[1][4] = 1; d[1][5] = 1;
	d[1][6] = 1; d[1][7] = 1; d[1][8] = 1;
	d[1][9] = 1;
	
 	for(int i = 2 ; i <= n ; i ++){
		
		for(int j = 0 ; j <= 9 ; j ++){
			for(int k = j ; k <= 9 ; k ++){
				d[i][j] += d[i-1][k] % 10007;
			}
		}
	}
	int sum = 0;
	for(int i = 0 ; i <= 9 ; i ++){
		sum += d[n][i] % 10007;
	}
	cout << sum % 10007;
	
	return 0;
}
