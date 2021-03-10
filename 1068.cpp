#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[50]; // adj[i] : ��� i�� �������� 
int parent[50];
vector<int> roots; // ��Ʈ ������ ��ȣ 
int n; // ����� ����
int result = 0; // �� Ʈ������ ���������� �� 
int erased; // ���� ����� ��ȣ
int leaf = 0; // ������ ��������� ���� 
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
		else{ // -1 �� �ԷµǸ� ��Ʈ����� 
			parent[i] = -1;
			roots.push_back(i); // ��Ʈ������ ����
			
		}
	}

	cin >> erased; // ������ ��ȣ 
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
