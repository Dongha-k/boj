#include <iostream>
#include <vector>
using namespace std;
vector<int> subset;
int arr[20];
int n, sum;
int cnt = 0;
void f(int k){
	if(k == n){
		if(subset.empty()) return;
		int result = 0;
		for(int u : subset){
			result += arr[u];
		}
		if(result == sum) cnt ++;
	}
	else{
		subset.push_back(k);
		f(k+1);
		subset.pop_back();
		f(k+1);
		
	}
}
int main(){
	cin >> n >> sum;
	for(int i = 0 ; i < n ; i ++){
		cin  >> arr[i];
	}
	
	f(0);
	cout << cnt;
	return 0;
}
