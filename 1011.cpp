#include <iostream>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int x, y;
		cin >> x >> y;
		y -= x;
		x = 0;
		int  i = 1;
		double p = 1;
		while(y >= p){
			if(y < p){
				break;
			}
			i++;
			p = i * i;
		}
		i--;
		
		
		
		int cnt = i;
		int cur = 0;
		int result = 2 * i - 1;
		int up = 0;
		if(i * i == y){
			up  = 0;
		}
		else{
			for(int j = i * i + 1; j <= y ; j ++){
				if(cur == 0){
					up ++;
				}
				cur ++;
				if(cur == cnt){
					cnt ++;
					cur = 0;
				}
			}
		}
		cout << up + result << '\n';
	}
	return 0;
}
