#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int rope[100000];
	int mw = 0;// max weight
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		cin >> rope[i];
	}
	sort(rope, rope+n);
	for(int i = 0 ; i < n ; i ++){
		mw = max(mw, rope[i] * (n - i));
	}
	cout << mw;
	return 0;
}
