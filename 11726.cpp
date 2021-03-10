#include <iostream>
using namespace std;
int main(){
	int d[1001], n;
	d[1] = 1;
	d[2] = 2;
	cin >> n;
	for(int i = 3 ; i <= n ; i ++){
		d[i] = d[i-1] % 10007 + d[i-2] % 10007;
	}
	cout << d[n] % 10007;
	return 0;
}
