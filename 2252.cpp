#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int N, M;

vector<int> v[320001]; // 노드, 간선정보 
int inDegree[320001]; // 진입 차수 


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
			if(--inDegree[v[curNode][i]] == 0){ // 새롭게 진입 차수가 0이 된다면 q에 넣기 
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
		inDegree[b]++; // 키가 더 큰 노드의 진입 차수 더함 
	}
	
	topologySort();
	
	return 0;
}
