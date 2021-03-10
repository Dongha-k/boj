#include <iostream>
using namespace std;
int main(){
	int N, l;
	cin >> N >> l;
	int a = 0 ,b = 0;
	int n = 0;
	for(int i = l ; i <= 100; i ++){
		a = i;
		b = (i * (i - 1)) /2;
		if((N - b)%a == 0){
			n =(N - b)/a;
			if(n < 0) continue;
			for(int j = n ; j < n + i ; j ++){
				cout << j << ' ';
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}
