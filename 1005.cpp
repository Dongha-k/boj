#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int _time[10001]; // 건물을 짓는데 걸리는 시간 
int result[10001]; // result[i] : 건물 i까지 짓는데 걸리는 최소 시간 
int inDegree[10001] = {0, }; // 진입차수
vector<int> adj[10001]; // 인접노드 
int t; // 테스트 케이스 갯수
int n; // 건물의 갯수
int k; // 건설 순서 규칙 갯수
void func(){
	queue<int> q;
	for(int i = 1 ; i <= n ; i ++){ 
		if(inDegree[i] == 0) {
			q.push(i);
			result[i] = _time[i]; 
		}	
	} // 가장 처음에 진입 차수가 0인 노드들을 큐에 삽입 
	for(int i = 0 ; i < n ; i ++){ // 각 노드에 대해서만 한번씩 처리해주면 되니깐 n번만 실행 
		int x = q.front();
		q.pop();
		for(int y : adj[x]){
			if(result[y] < result[x] + _time[y]){
				result[y] = result[x] + _time[y];
			}
			if(--inDegree[y] == 0){
				q.push(y);
			}
		}
	}
}
int main(){
	cin >> t; // 테스트 케이스 갯수 입력
	while(t--){
		cin >> n >> k;
		// 진입차수, 결과값 초기화, 인접노드 초기화 
		for(int i = 1 ; i <= n ; i ++){
			inDegree[i] = 0;
			result[i] = 0;
			adj[i].clear();
		}
		for(int i = 1 ; i <= n ; i ++){
			cin >> _time[i];
		}
		while(k--){
			int x, y;
			cin >> x >> y; // y가 만들어지기 전에 x가 만들어져야함 
			inDegree[y]++; // y의 진입차수 ++
			adj[x].push_back(y); // x의 인접노드에 포함 
		}
		int w;
		cin >> w;
		func();
		cout <<result[w] << '\n';
	}
	return 0;
}
