#include <iostream>
using namespace std;
int d[1000001] = {0, 1, 3};
int main(){
	int t;
	cin >> t;
	
	while(t--){
		int x;
		cin >> x;
		if(d[x] != 0){
			cout << d[x] % 1000000009;
		}
		else{
			for(int i = 2 ; i <= x ; i++){
				if(d[i] == 0) d[i] = d[i - 1] + 2 * d[i-2] + 4 * d[i -3]; 
			}
			cout << d[x] + 3 << '\n';
		}
	}
	return 0;
}


