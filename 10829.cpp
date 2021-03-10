#include <iostream>
#include <stack>
using namespace std;
int main(){
	stack<int> s;
	long long n;
	int point = 0;
	cin >> n;
	if(n == 0){
		cout << 0; return 0;
	}
	while(n != 0){
		s.push(n%2);
		n /= 2;
	}
	
	while(!s.empty()){
		cout << s.top(); s.pop();
	}
	return 0;
}
