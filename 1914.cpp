#include <iostream>
using namespace std;
int n;
void f(int from, int by, int to, int k){
	if(k >= n) return;
	f(from, to, by, k+1);
	cout << from << ' '<< to << '\n';
	f(by, from , to, k+1);
}
int main(){
	cin >> n;
	long long result = pow(2, n)-1;
	cout << result <<'\n';
	if(n > 20) return 0;
	f(1,2,3,0);
	return 0;
}
