#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int arr[1001];
	int d[1001];
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	
	int result = arr[0];
	d[0] = arr[0];
	for(int i = 1 ; i < n ; i++){
		d[i] = arr[i] + d[i-1];
		result += d[i];
	}
	cout << result;
	return 0;
}
