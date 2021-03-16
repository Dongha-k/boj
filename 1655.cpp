#include <iostream>
using namespace std;
int cnt[20001] = {0, };
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int _min = 100000;
	int _max = -100000;
	for(int i = 0 ; i < n ; i ++){
		int x;
		cin >> x;
		_min = min(_min, x);
		_max = max(_max, x);
		cnt[x] ++;
		for(int i = _min ; i <= _max ; i ++){
			
		}
		
	}
	return 0;
}
