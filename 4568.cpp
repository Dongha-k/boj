#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef pair<int, char> P;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int level = 0;
	while(true){
		cin >> n;
		if(n == 0) break;
		string s;
		cin >> s;
		queue<P> q;
		priority_queue<P> pq;
		int pre[26] = {0, };
		int up = 0;
		cout << "Simulation " << ++level << '\n';
		for(int i = 0 ; s[i] != '\0' ; i ++){
			if(s[i] == '!'){
				int cnt = 0;
				while(!pq.empty()){
					if(-pq.top().first == pre[pq.top().second-'A']){
						q.push(pq.top());
						pq.pop();
					}
					else{
						pq.pop();
					}
				}
				while(!q.empty()){
					if(q.size() <= n){
						cout << q.front().second;
					}
					pq.push(q.front());
					q.pop();
				}
				cout << '\n';
			}
			else{
				char ch = s[i];
				pre[ch-'A'] = up++;
				pq.push({-pre[ch-'A'], ch});
			}
		}
	}
	return 0;
}
