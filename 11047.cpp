#include <iostream>
#include <stack>
using namespace std;
int main(){
	int n, price;
	stack<int> s;
	cin >> n >> price;
	while(n--){
		int x;
		cin >> x;
		s.push(x);
	}
	int cur = price;
	int cnt = 0;
	while(!s.empty()){
		int y = s.top();
		s.pop();
		if(y <= cur){
			cnt += cur / y;
			cur = cur % y;
		}
		if(cur == 0){
			cout << cnt;
			break;
		}
	}
	return 0;
}
