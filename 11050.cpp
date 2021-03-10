#include <iostream>
using namespace std;
int comb(int n, int k){
	if(k == 0) return 1;
	else if(k == n) return 1;
	else{
		return comb(n-1,k-1) + comb(n-1, k);
	}
}
int main(){
	int n,k;
	cin >> n >> k;
	cout << comb(n, k);

	return 0;
}
