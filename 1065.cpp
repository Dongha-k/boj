#include <iostream>
using namespace std;
int result[3];
int cnt = 99;
int n;
void f(int k){
	if(k == 3){
		if(result[0] - result[1] != result[1] - result[2]) return;
		if(result[0] * 100 + result[1] * 10 + result[2] > n) return;
		cnt ++;
	}
	else{
		for(int i = 0 ; i < 10 ; i ++){
			if(k == 0 and i == 0) continue;
			result[k] = i;
			f(k+1);
		}
	}
}
int main(){
	cin >> n;
	if(n < 100){
		cout << n;
		return 0;
	}
	f(0);
	cout << cnt;
	
	return 0;
}
