#include <iostream>
#include <queue>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, x;
	priority_queue<int> pq;
	cin>>n;
	while(n--){
		cin >> x;
		if(x==0 && pq.empty()) cout <<0 << '\n';
		else if(x == 0){
			cout <<-pq.top() << '\n';
			pq.pop();
		}
		else{
			pq.push(-x);
		}
	}
	return 0;
}
