#include <iostream>

using namespace std;

pair<long long, long long> p[101];

pair<long long, long long> fibo(int n){
	if(n == 0) return make_pair(1, 0);
	else if(n == 1) return make_pair(0, 1);
	else if(p[n].first != 0 and p[n].second != 0) return p[n];
	else{
		pair<long long, long long> a, b;
		a = fibo(n-1);
		b = fibo(n-2);
		
		p[n].first = a.first + b.first;
		p[n].second = a.second + b.second;
		return p[n];
	}
}

int main(){
	int num;
	int a;
	pair<long long, long long > result;
	
	cin >> num;
	
	while(num--){
		
		cin >> a;
		result = fibo(a);
		
		cout << result.first << " " << result.second << endl;
	}	
	
	return 0;
}
