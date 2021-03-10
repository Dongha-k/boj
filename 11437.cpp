#include <iostream>
#include <vector>

using namespace std;

int parent[50001];
int depth[50001];
vector<int> trees[50001];
bool visited[50001];
int cnt = 0; 
int n; //��� ���� 

int getParent(int k){ // �ְ����� ��� ��ȣ�� ��ȯ
	if(parent[k] == k) return k; // �θ���� �ڽ��� ���� ���̶�� �ְ������� 
	return getParent(parent[k]); 
}

void makePair(int a, int b){ // �� ���� ��带 ���̴µ� ���ΰ� �ٸ� Ʈ���� ���ϸ� ��Ʈ��尡 �� ���� Ʈ������ ��尡 �θ��尡��. 
	int parentA = getParent(a);
	int parentB = getParent(b);
	if(parentA < parentB){ // a�� Ʈ���� ��Ʈ��� ��ȣ�� �� ������
		parent[b] = a;
		trees[a].push_back(b);
	}
	else{
		parent[a] = b;
		trees[b].push_back(a);
	}
}


void defineDepth(int x){ //DFS�� �̿��Ͽ� �� ����� depth �� ���� 
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
		
		if(gap < 0){ // y�� ���̰� �� ���� ��� 
			gap = -gap;
			while(gap--){
				y = parent[y]; // �� ����� ���̰� �������� �� ���̰� �� ���� ��带 ������ ����ŭ �θ��带 Ÿ�� �ö� 
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
