#include <iostream>
#include <stack>
using namespace std;
int main(){
	int x;
	cin >> x;
	x = 1000 - x;
	stack<int> s;
	for(auto i : {1, 5, 10, 50, 100, 500}){
		s.push(i);
	}
	int cnt = 0;
	while(x != 0){
		int y = s.top();
		s.pop();
		if(y <= x){
			cnt += x / y;
			x = x % y;
		}
	}
	cout << cnt;
	return 0;
}
