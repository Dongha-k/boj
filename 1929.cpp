#include <iostream>
using namespace std;
bool check[1000001] = {false, };
int main(){
	int m, n;
	cin >> m >> n;
	check[1] = true;
	for(int i = 2 ; i <= n ; i ++){
		for(int j = i + i; j <= n ; j = j + i){
			check[j] = true; // 소수가 아니면true 
		}
	}
	for(int i = m ; i <=n ; i ++){
		if(!check[i]) cout << i << '\n';
	}
	
	return 0;
}
