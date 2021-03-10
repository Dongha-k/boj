#include <iostream>
using namespace std;
long long pow(long long c, long long k){
	if(k == 1) return c;
	else if(k%2 == 0){
		int half = pow(c, k/2);
		return half * half;
	}
	else{
		long long half = pow(c, (k-1)/2);
		return half * half * pow(c, 1);
	}
}
long long n, x, y;
void f(long long k, long long n){
	long long l = pow(2, k);
	if(k == 1){
		if(x < l / 2 and y < l / 2){ // 1��и鿡 ������ ��� 
			cout << n;		
		}
		else if(x < l / 2 and y >= l / 2){ // 2��и� 
			cout << n + 1;
		}
		else if(x >= l / 2 and y < l / 2){ // 3��и� 
			cout << n + 2;
		}
		else{ // 4��и�
			cout << n + 3;
		}
		return;
	}
	if(x < l / 2 and y < l / 2){ // 1��и鿡 ������ ��� 
//		cout << "1��и� ";
		f(k-1, n);
	}
	else if(x < l / 2 and y >= l / 2){ // 2��и� 
		y -= l / 2;
//		cout << "2��и� ";
		f(k-1, n + l * l / 4);
	}
	else if(x >= l / 2 and y < l / 2){ // 3��и� 
		x -= l / 2;
//		cout << "3��и� ";
		f(k-1, n + 2 * l * l / 4);
	}
	else{ // 4��и�
		x -= l / 2;
		y -= l / 2; 
//		cout << "4��и� ";
		f(k-1, n + 3 * l * l / 4);
	}
	
	
}
int main(){
	cin >> n >> x >> y;

	f(n, 0);
	return 0;
}
