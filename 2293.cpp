#include <iostream>
using namespace std;
int n, k;
int coin[100];
int solve[100001];
int main(){
	cin >> n >> k;
	for(int i = 0 ; i < n ; i ++){
		cin >> coin[i];
	}
	solve[0] = 1;
	for(int i = 1 ; i <= k ; i ++){
		solve[i] = 0;
		for(int j = 0 ; j < n; j ++){
			int c = coin[j];
			if(i-c >= 0){
				solve[i] += solve[i-c];
			}
		}
	}
//	cout << solve[k];
	for(int i = 1;i <= k ; i ++){
		cout <<i <<" : " << solve[i] <<endl;
	}
	return 0;
}
