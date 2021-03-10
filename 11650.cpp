#include <iostream>

using namespace std;
int main(){
	
	int n, x, y;
	bool check[500][500];
	for(int i = 0 ; i < 500 ; i ++){
		for(int j = 0 ; j < 500 ; j ++){
			check[i][j] = false;
		}
	}
	
	while(n--){
		cin >> x >> y;
		x+= 100000;
		y+= 100000;
		
	}
	return 0;
}
