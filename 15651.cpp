#include <iostream>
using namespace std;
int arr[10], n, m;

void f(int k){
	if(k == m){
		for(int i = 0 ; i < m ; i ++){
			cout << arr[i] << ' ';
		}
		cout << '\n'; 
		return;
	}
	
	for(int i = 1 ; i <= n ; i ++){
		arr[k] = i;
		f(k+1);
		
	}
}
int main(){
	cin >> n >> m;
	f(0);
	return 0;
}
