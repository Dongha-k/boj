#include <iostream>
using namespace std;
int main(){
	int k[11] = {0, };
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		int x;
		cin >> x;
		int count = 0;
		for(int j = 1 ; j <= n ; j ++){
			if(k[j] == 0 and count == x){
				k[j] = i;
				break;
			}
			if(k[j] == 0) count ++;	
		}
	}
	for(int i = 1 ; i <= n ; i++){
		cout << k[i] << ' ';
	}
	return 0;
}
