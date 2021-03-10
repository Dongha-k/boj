#include <iostream>
using namespace std;
int main(){
	int x, y;
	cin >> x >> y;
	int temp = y;
	
	for(int i = 2 ; i >= 0 ; i --){
		cout << x * (y%10) << '\n';
		y /= 10;
	}
	cout << temp * x;
	return 0;
}
