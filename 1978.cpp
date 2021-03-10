#include <iostream>
using namespace std;
int main(){
	bool check[1001] = {false, };
	check[1] = true;
	for(int i = 2 ; i <= 1000 ; i ++){
		for(int j = i + i ; j <= 1000 ; j += i){
			if(!check[j]) check[j] = true;
		}
	}

	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 0 ; i < n ; i ++){
		int x;
		cin >> x;
		if(!check[x]) cnt ++;
	}
	cout << cnt;
	return 0;
}
