#include <iostream>
#include <vector>
using namespace std;

int n; // 노드의 갯수
vector <int> adj[50001];
int depth[50001];

vector<pair<int, int>> eulerTree; // <노드 번호, 해당 노드 깊이> 
int _count = 1;

void eulerTour(int s, int e){
	eulerTree.push_back(make_pair(s, _count));
	for(int u : adj[s]){
		if(u != e) {
			_count ++;
			eulerTour(u, s);
			eulerTree.push_back(make_pair(s, _count-1));
			_count --;
			
		}
	}
}



int main(){
	int first, second;
	cin >> n;
	for(int i = 0 ; i < n - 1; i ++){
		cin >> first >> second;
		adj[first].push_back(second);
		adj[second].push_back(first);
	}
	
	eulerTour(1, 0);

	
	
	int t; cin >> t;
	
	while(t--){
		int min = 10000;
		int idx = 0, i = 0, j = 0;
		cin >> first >> second;
		
		for(int k = 0 ; k < eulerTree.size() ; k ++){
			if(first == eulerTree[k].first){
				i = k;
				break;
			}
		}
		for(int k = 0 ; k < eulerTree.size() ; k ++){
			if(second == eulerTree[k].first){
				j = k;
				break;
			}
		}
		if(i < j){
			for(int k = i ; k <= j ; k ++){
				if(eulerTree[k].second < min){
					idx = eulerTree[k].first;
					min = eulerTree[k].second;
				}
			}
		}
		else if(j < i){
			for(int k = j ; k <= i ; k ++){
				if(eulerTree[k].second < min){
					idx = eulerTree[k].first;
					min = eulerTree[k].second;
				}
			}
		}
		else{
			idx = idx = eulerTree[i].first;
		}
		cout << idx << '\n';
		
	}
	return 0;
}
