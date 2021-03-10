#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, n;
vector<int> result;
int arr[10];
vector<int> seq;
void f(int k){
	if(k == n){
		for(int i = 0 ; i < n-1 ; i ++){
			if(arr[i+1] < arr[i]){
				return;
			}
		}
		for(int i = 0 ; i < n ; i ++){
			cout << seq[arr[i]]<< ' ';
		}
		cout << '\n';
	}
	else{
		for(int i = 0 ; i < m ; i ++){
			arr[k] = i;
			f(k + 1);
		}
	}
}
int main(){
	cin >> m >> n;
	for(int i = 0 ; i < m ; i++){
		int x;
		cin >> x;
		seq.push_back(x);
	}
	sort(seq.begin(), seq.end());
	f(0);
	return 0;
}
