#include <iostream>
using namespace std;
int main(){
	long long d[101] = {0, 1, 1, 1, 2, 2, 0, };
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 6 ; i <= n ; i ++){
			d[i] = d[i-1] + d[i-5];
		}
		cout << d[n] << '\n';
	}
	return 0;
}
