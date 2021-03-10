#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[50]; // adj[i] : 노드 i의 인접노드들 
int parent[50];
vector<int> roots; // 루트 노드들의 번호 
int n; // 노드의 갯수
int result = 0; // 각 트리들의 리프노드들의 합 
int erased; // 지울 노드의 번호
int leaf = 0; // 누적된 리프노드의 갯수 
void dfs(int s, int e){
	if(s == erased) return;
	if(adj[s].empty()) leaf ++;
	
	
	for(int u : adj[s]){
		if(u != e) dfs(u, s);
	}
}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		int number;
		cin >> number;
		if( number >= 0){
			adj[number].push_back(i);
			parent[i] = number;
		}
		else{ // -1 이 입력되면 루트노드임 
			parent[i] = -1;
			roots.push_back(i); // 루트노드들의 집합
			
		}
	}

	cin >> erased; // 지울노드 번호 
	int p = parent[erased];
	int i = 0;
	for(vector<int>::iterator it = adj[p].begin() ; it != adj[p].end() ; it++){
		
		if(adj[p][i] == erased){
			it = adj[p].erase(it);
			break;
		}
		else{
			i++;
		}
	}
	
	
	for(int u : roots){
		dfs(u, -1);
		result += leaf;
		leaf = 0;
	}
	cout << result;
	
	return 0;
}
