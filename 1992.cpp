#include <iostream>
using namespace std;
int board[65][65];
void search(int x, int y, int k){
	int c = board[x][y];
	if(k == 1){
		cout << c;
		return;
	}
	bool flag = false;
	for(int i = x ; i < x + k ; i ++){
		for(int j = y ; j < y + k ; j ++){
			if(c != board[i][j]){
				flag = true;
				break;
			}
		}
		if(flag) break;
	}
	if(!flag){
		cout << c;
		return;
	}
	else{
		cout << '(';
		search(x, y, k/2);
		search(x, y+k/2, k/2);
		search(x+k/2, y, k/2);
		search(x+k/2, y+k/2, k/2);
		cout << ')';
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= n ; j ++){
			char x;
			cin >> x;
			board[i][j] = x -'0';
		}
	}
	search(1,1,n);
	return 0;
}
