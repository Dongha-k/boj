#include <iostream>
using namespace std;
int d[30][30];
int c(int n, int k){
	if(k == 0 or k == n) return 1;
	else if(d[n][k] != 0) return d[n][k];
	else return d[n][k] = c(n-1, k-1) + c(n-1, k);
}
int main(){
	int t, m, n;
	cin >> t;
	while(t--){
		cin >> m >> n;
		cout << c(n, m) << '\n';
	}
	return 0;
}

