#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int main(){
	int n;
	cin >> n;
	priority_queue<pii> pq;
	while(n--){
		int x;
		cin >> x;
		if(x < 0) pq.push({x, 1}); // 음수일 경우 절댓값이 같을 때 우선 순위가 더 높으므로 second에 1 
		else if(x > 0) pq.push({-x, 0});
		else{ // x == 0
			if(pq.empty()){
				cout << 0 << '\n';
			}
			else{
				pii p = pq.top();
				if(p.second == 0) p.first = -p.first;
				pq.pop();
				cout << p.first << '\n';
			}
		}
	}
	return 0;
}
