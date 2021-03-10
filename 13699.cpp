#include <iostream>
using namespace std;
long long t[36];
int main(){
	int n;
	cin >> n;
	t[0] = 1;
	for(int i = 1 ; i <= n ; i ++){
		t[i] = 0;
		for(int j = 0 ; j < i ; j ++){
			if(j < i/2){
				t[i] += t[j]*t[i-1-j];
			}
			else{
				t[i] += t[j]*t[i-j-1];
			}
		}
	}
	cout << t[n];
	return 0;
}
