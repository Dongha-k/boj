#include <iostream>
#include <stack>
using namespace std;

int main(){
	long long n, c, sum = 0;
	stack<long long> s;
	
	cin >> c;
	for(int i = 0 ; i < c ; i++){
		cin >> n;
		if(n == 0){
			s.pop();
		}
		else{
			s.push(n);
		}
	}
	while(!s.empty()){
		sum += s.top();
		s.pop();
	}
	
	cout << sum;
	
	
	
	return 0;
}
