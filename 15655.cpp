#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n, m, result[10];
bool check[10] = {false, };

void f(int k){
	if(k == m){
		for(int i = 0 ; i < m - 1 ; i ++){
			if(v[result[i]] > v[result[i+1]]) return;
		}

		for(int i = 0 ; i < m ; i ++){
			cout << v[result[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	for(int i = 0 ; i < n ; i ++){
		if(!check[i]){
			result[k] = i;
			check[i] = true;
			f(k+1);
			check[i] = false;
		}
	}
	
}

int main(){
	cin >> n >> m;
	int num;
	for(int i = 0 ; i < n ; i ++){
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	f(0);
	return 0;
}
