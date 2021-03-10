#include <iostream>
using namespace std;
int a, b, c;
long long f(int k){
	if(k == 1) return a;
	else if(k % 2 == 0){
		long long half = f(k/2) % c;
		return (half * half)%c;
	}
	else{
		long long half = f((k-1)/2) % c;
		return ((half * half) % c * f(1))%c;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b >> c;
	cout << f(b) % c;
	return 0;
}
