#include <iostream>
using namespace std;
int mod = 10007;
int comb[1001][1001] = {};
int c(int n, int k){
	if(comb[n][k] != 0) return comb[n][k];
	else if(k == 0) return comb[n][k] = 1;
	else if(k == n) return comb[n][k] = 1;
	else return comb[n][k] = (c(n-1, k-1)%mod + c(n-1, k)%mod)%mod;
}
int main(){
	int n, k;
	cin >> n >> k;
	cout << c(n, k);
	return 0;
}
