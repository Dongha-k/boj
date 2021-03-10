#include <iostream>
#include <algorithm>
int arr[101];
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	for(int i =0 ; i < n ; i ++){
		cin >> arr[i];
	}
	int _max = 0;
	for(int i = 0 ;i <n; i++){
		for(int j = i+1; j < n; j ++){
			for(int k = j + 1 ; k < n ; k ++){
				if(arr[i]+arr[j]+arr[k] <= m) _max = max(_max, arr[i]+arr[j]+arr[k]);
				if(_max == m){
					cout << m;
					return 0;
				}
			}
		}
	}
	cout << _max;
	return 0;
}
