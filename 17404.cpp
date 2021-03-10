#include <iostream>
using namespace std;
int d[1001][3][3];
int spare[1001][3];
int main(){
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 0 ; j < 3 ; j ++){
			cin >> spare[i][j];
		}
	}
	d[1][0][0] = spare[1][0];
	d[1][1][1] = spare[1][1];
	d[1][2][2] = spare[1][2];
 	
 	d[2][0][1] = spare[2][0] + d[1][1][1];
	d[2][0][2] = spare[2][0] + d[1][2][2];
	
	d[2][1][0] = spare[2][1] + d[1][0][0];
	d[2][1][2] = spare[2][1] + d[1][2][2];
	
	d[2][2][0] = spare[2][2] + d[1][0][0];
	d[2][2][1] = spare[2][2] + d[1][1][1];
	
	
	for(int i =0 ; i < 3 ; i ++){
		for(int j = 0 ; j < 3 ; j  ++){
			if(i == j) d[3][i][j] = spare[3][i] + min(d[2][(j+1)%3][j], d[2][(j+2)%3][j]);
			else{
				d[3][i][j] = spare[3][i] + d[2][3-i-j][j];
			}
		}
	}
	
	for(int i = 4 ; i <= n ; i ++){	
		for(int j = 0 ; j < 3 ; j ++){
			for(int k = 0 ; k < 3 ; k ++){
				d[i][j][k] = spare[i][j] + min(d[i-1][(j+1)%3][k], d[i-1][(j+2)%3][k]);
			}
		}
	}
	int _min = 100000000;
	for(int i = 0 ; i < 3 ; i ++){
		for(int j = 0 ; j < 3; j ++){
			if(i == j){
				continue;
			}
			_min = min(_min, d[n][i][j]);
		}
	}
	cout <<_min;
	return 0;
}
