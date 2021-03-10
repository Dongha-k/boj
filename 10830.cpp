#include <iostream>
using namespace std;
int base[5][5];
typedef struct{
	int matrix[5][5];
} M;
int mod = 1000;
int n;
long long b;
M mul(M a, M b){
	M c;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++){
			c.matrix[i][j] = 0;
			for(int k = 0 ; k < n ; k ++){
				c.matrix[i][j] += ((a.matrix[i][k])%mod * (b.matrix[k][j]%mod)) % mod;
			}
		}
	}
	return c;
}
M f(long long k){
	if(k == 1){
		M m;
		for(int i = 0 ;i < n ; i++){
			for(int j = 0 ; j < n ; j ++){
				m.matrix[i][j] = base[i][j];
			}
		}
		return m;
	}
	else if(k % 2 == 0){
		auto half = f(k/2);
		return mul(half, half);
	}
	else{
		auto half = f((k-1)/2);
		return mul(mul(half, half), f(1));
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> b;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++){
			cin >> base[i][j];
		}
	}
	M m = f(b);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j ++){
			cout << m.matrix[i][j]%mod << ' ';
		}
		cout << '\n';
	}
	return 0;
}
