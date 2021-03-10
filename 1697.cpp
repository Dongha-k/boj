#include <iostream>
#include <queue>
#define MAX 200001
using namespace std;
int d[MAX]; // d[i] : i위치까지 올 수 있는 시간 중 최단시간
int main(){
	queue<int> q;
	int n, k;
	cin >> n >> k;
	fill(d, d+MAX, -1);
	q.push(n);
	d[n] = 0;
	while(!q.empty()){
		int cur = q.front();
		if(cur == k){
				cout << d[cur];
				return 0;
			}
		q.pop();
		for(int i = 0 ; i < 3 ; i ++){
			int next;
			if(i == 0) next = cur - 1;
			else if(i == 1) next = cur + 1;
			else{ // if i == 2 :
				next = cur * 2;
			}// next 결정
			if(next < 0 or next > 200000) continue; // hmm.....
			if(d[next] != -1) continue; 
			// 방문하지 않은 곳일 때, 
			q.push(next);
			d[next] = d[cur] + 1;
		}
	}
	return 0;
}
