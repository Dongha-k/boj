#include <iostream>
using namespace std;

int n, m;
int check[10] = {false, };
int arr[10];
void f(int k){
	if(k == m){
		for(int i = 0 ; i < m - 1 ; i ++){
			if(arr[i] > arr[i+1]){
				return;
			}
		}
		for(int i = 0 ; i < m ; i ++){
			cout << arr[i]  << ' ' ;
			
		}
		cout << '\n';
		return;
	}
	for(int i = 1 ; i <= n ; i ++){
		if(!check[i]){
			arr[k] = i;
			check[i]  = true;
			f(k + 1);
			check[i] = false;
		}
	}
}

int main(){
	cin >> n >> m;
	f(0);
	
	return 0;
}
