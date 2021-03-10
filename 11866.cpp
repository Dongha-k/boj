#include <queue>
#include <iostream>
using namespace std;
int main(){
	int n, k;
	int count = 0;
	queue<int> q;
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++){
		q.push(i);
	}
	cout << '<';
	while(!q.empty()){
		int x = q.front();
		q.pop();
		count ++;
		if(count != k){
			q.push(x);
		}
		else{
			count = 0;
			if(q.empty()){
				cout << x;
			}
			else{
				cout << x << ", ";
			}
		}
	}
	cout << '>';
	return 0;
}
