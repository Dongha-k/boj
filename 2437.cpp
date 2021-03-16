#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
	int n;
	int arr[1000];
	int top = 0;
	cin >> n;
	for(int i =0 ;i < n ; i ++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
	for(int i =0 ;i < n ; i ++){
		int x = arr[i];
		if(x - top > 1){
			cout << top + 1;
			return 0;
		}
		top += x;
	}
	cout << top +1 ;
	return 0;
}
