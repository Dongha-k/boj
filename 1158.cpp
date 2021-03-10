#include <iostream>
#include <queue>
using namespace std;
int main(){
	queue<int> q;
	int n, k;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++){
		q.push(i);
	}
	int count = 0;
	cout << '<';
	while(!q.empty()){
		count ++;
		if(count == k){
			if(q.size() == 1) cout << q.front() << '>'; 
			else cout << q.front() <<", ";
			count = 0;
		}
		else{
			q.push(q.front());
		}
		q.pop();
	}
	return 0;
}
