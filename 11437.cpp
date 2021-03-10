#include <iostream>
#include <vector>

using namespace std;

int parent[50001];
int depth[50001];
vector<int> trees[50001];
bool visited[50001];
int cnt = 0; 
int n; //노드 갯수 

int getParent(int k){ // 최고조상 노드 번호를 반환
	if(parent[k] == k) return k; // 부모노드와 자신이 같은 값이라면 최고조상임 
	return getParent(parent[k]); 
}

void makePair(int a, int b){ // 두 개의 노드를 붙이는데 서로가 다른 트리에 속하면 루트노드가 더 작은 트리쪽의 노드가 부모노드가됨. 
	int parentA = getParent(a);
	int parentB = getParent(b);
	if(parentA < parentB){ // a쪽 트리의 루트노드 번호가 더 작으면
		parent[b] = a;
		trees[a].push_back(b);
	}
	else{
		parent[a] = b;
		trees[b].push_back(a);
	}
}


void defineDepth(int x){ //DFS를 이용하여 각 노드의 depth 값 대입 
	if(visited[x]){
		return;
	}
	visited[x] = true;
	depth[x] = cnt++;
	for(int i = 0 ; i < trees[x].size() ; i ++){
		int y = trees[x][i];
		defineDepth(y);
		cnt--;
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 1; i <= n ; i ++){
		visited[i] = false;
	}
	
	int a, b;
	
	for(int i = 0 ; i < n - 1 ; i ++){

		cin >> a >> b;
		
		if(parent[a] == 0) parent[a] = a;
		if(parent[b] == 0) parent[b] = b;
		
		makePair(a, b);

	}
	defineDepth(1);
	
	
	
	int t, x, y, gap;
	cin >> t;
	
	
	while(t--){
		cin >> x >> y;
		gap = depth[x] - depth[y];
		
		if(gap < 0){ // y의 깊이가 더 깊은 경우 
			gap = -gap;
			while(gap--){
				y = parent[y]; // 두 노드의 깊이가 같아지게 끔 깊이가 더 깊은 노드를 깊이의 차만큼 부모노드를 타고 올라감 
			}
		}
		else{
			while(gap --){
				x = parent[x];
			}
		}
		
		while(1){
			if(x == y){
				cout << x << '\n';
				break;
			}
			x = parent[x];
			y = parent[y];
		}
	}
	return 0;
}
