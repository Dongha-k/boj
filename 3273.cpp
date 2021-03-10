#include <iostream>
#include <set>
using namespace std;
int arr[100001];
int main(){
	int n, k;
	set<int> s;
	
	cin>>n;
	for(int i = 0 ; i < n ; i ++){
		int x;
		cin >> x;
		arr[i] = x;
		s.insert(x);
	}
	cin >> k;
	int cnt = 0;
	for(int i = 0 ; i < n ; i ++){
		int y = arr[i];
		if(s.find(k-y) != s.end()) cnt ++; 
	}
	
	cout << cnt/2;
	
	return 0;
}
