#include <iostream>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	// k�� ��� ° �밢���� �����ϴ��� �˾ƾ��� 
	// 1, 3, 6, 10, 15, 21, 28, ...
	int sum = 0;
	int dia;
	for(int i = 1 ; i <= n ; i ++){
		sum += i;
		if(k > sum){
			dia = i+1;
		}
	}
	int cur = k - (dia * (dia-1)) /2; 
	cout << dia << ": " << cur;
	return 0;
}
