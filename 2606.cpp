#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool visited[101] = {false, };
vector<int> adj[101];
int V, E; // Á¤Á¡ÀÇ °¹¼ö, °£¼±ÀÇ °¹¼ö
int main(){
	cin >> V >> E;
	for(int i = 0 ;i < E ;i ++){
		int first, second;
		cin >> first >> second;
		adj[first].push_back(second);
		adj[second].push_back(first);		
	}
	queue<int> q;
	int cnt = 0;
	q.push(1);
	visited[1] = true;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 0 ; i < adj[cur].size() ; i ++){
			int next = adj[cur][i];
			if(!visited[next]){
				visited[next] = true;
				cnt ++;
				q.push(next);
			}
		}
	}
	cout << cnt;
	
	return 0;
} 
