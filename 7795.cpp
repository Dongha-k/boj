#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	int A[20000];
	while(t--){
		int n, m;
		int cnt = 0;
		cin >> n >> m;
		for(int i = 0 ; i < n ; i ++){
			int x;
			cin >> x;
			A[i] = - x;
		}
		sort(A, A+n);
		for(int i = 0 ; i < m ; i ++){
			int x;
			cin >> x;
			for(int j = 0 ; j < n ; j ++){
				if(x < -A[j]) cnt ++;
				else break;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
