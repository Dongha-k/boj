#include <iostream>
using namespace std;
long long d[100] = {0, 1};
int main(){
	int n; cin >> n;
	if(n == 0) cout << 0;
	else if(n == 1) cout << 1;
	else{
		for(int i = 2 ; i <= n ; i ++){
			d[i] = d[i-1] + d[i-2];
		}
		cout << d[n];
	}
	return 0;
}
