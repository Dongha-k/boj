#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int a = n / 5 ; a >= 0 ; a --){
		for(int b = n / 3 ; b >= 0 ; b --){
			if(a * 5 + b * 3 == n){
				cout << a + b;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}
