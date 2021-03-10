#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int N, M;

vector<int> v[320001]; // ���, �������� 
int inDegree[320001]; // ���� ���� 


void topologySort(){
	queue<int> q;
	
	for(int i = 1 ; i <= N ; i ++){
		if(inDegree[i] == 0){
			q.push(i);
		}
	}
	
	int curNode;
	for(int i = 1 ; i <= N ; i ++){
		curNode = q.front();
		cout << curNode<< " ";
		q.pop();
		for(int i = 0 ; i < v[curNode].size() ; i ++){
			if(--inDegree[v[curNode][i]] == 0){ // ���Ӱ� ���� ������ 0�� �ȴٸ� q�� �ֱ� 
				q.push(v[curNode][i]);
			}
		}
	}
}

int main(){
	cin >> N >> M;
	
	int a, b;
	
	for(int i = 0 ; i < M ; i ++){
		cin >> a >> b;
		v[a].push_back(b);
		inDegree[b]++; // Ű�� �� ū ����� ���� ���� ���� 
	}
	
	topologySort();
	
	return 0;
}
