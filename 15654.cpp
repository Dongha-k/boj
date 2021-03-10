#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int n, m, result[10];
bool check[10] = {false, };

void F(int k){
	if(k == m){
		for(int i = 0 ; i < m ; i ++){
			cout << v[result[i]]<< ' ';
		}
		cout<< '\n';
		return;
	}
	for(int i = 0 ; i < n ; i ++){
		if(!check[i]){
			check[i] = true;
			result[k] = i;
			F(k+1);
			check[i] = false;
		}
	}
	
}

int main(){
	cin >> n >> m;
	int number;
	for(int i = 0 ; i < n ; i ++){
		cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	F(0);
	
	return 0;
}
