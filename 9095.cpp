#include <iostream>
using namespace std;
int n;
int d[12] = {0, 1, 2, 4, 7};
int count(int n){
	if(d[n] != 0) return d[n];
	else{
		return d[n] = count(n-1) + count(n-2) + count(n-3);
	}
}

int main(){
	cin >> n;
	int a;
	while(n--){
		cin >> a;
		cout << count(a) << "\n";
	}
	return 0;
}
