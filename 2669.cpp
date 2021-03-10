#include <iostream>
using namespace std;
int board[101][101];
int result = 0;
bool check[101][101];
int main(){
	for(int i = 0 ; i <= 100 ; i++){
		fill(check[i], check[i] + 101, false);
	}
	for(int i = 0 ; i < 4 ; i ++){
		int fx, fy, ex, ey;
		cin >> fx >> fy >> ex >> ey;
		for(int i = fx ; i < ex ; i ++){
			for(int j = fy ; j < ey ; j ++){
				board[i][j] = 1;
			}
		}
	}
	for(int i = 0 ; i < 101 ; i ++){
		for(int j =0 ; j < 101 ; j ++){
			if(board[i][j] == 1 and !check[i][j]){
				result++;
				check[i][j] = true;
			}
		}
	}
	cout << result;
	return 0;
}
