#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001


using namespace std;

int V, E;
vector<pair<int, int> > a[MAX], b[MAX]; // b = 역방향으로 이동 
int inDegree[MAX], result[MAX], c[MAX];
 


void search(int start, int finish){
	queue<int> q;
	// 시작점 노드를 큐에 먼저 삽입 
	q.push(start);
	
	while(!q.empty()){ // 각 노드별 임계 시간을 구함 = 시작점 노드에서부터 걸리는 시간 중 최대 시간(거리)
		int x = q.front();
		q.pop();
		for(int i = 0 ; i < a[x].size() ; i ++){
			pair<int, int> y = make_pair(a[x][i].first, a[x][i].second);
			if(result[y.second] <= y.first + result[x]){
				result[y.second] = y.first + result[x];
			}
			// 새롭게 진입 차수가 0이 된 정점을 큐에 삽입 
			if(--inDegree[y.second] == 0){
				q.push(y.second); 
			}
		}
	}
	
//	for(int i = 1 ; i <= V ; i ++){
//		cout << result[i] << " ";
//	}
	//결과를 역추적함 
	int count = 0;
	q.push(finish);
	
	while(!q.empty()){
		int y = q.front();
		q.pop();
		for(int i = 0 ; i < b[y].size() ; i ++){
			pair<int, int> x = make_pair(b[y][i].first, b[y][i].second);
			// 최장 경로에 포함되는 간선인지 확인
			if(result[y] - result[x.second] == x.first) {
				count ++;				
				if(c[x.second] == 0){ // 방문처리 
					q.push(x.second);
					c[x.second] = 1;
				}
			}
		}
	}
	cout << result[finish] << "\n" << count;
}



int main(){
	int d, x, y;
	int start, finish;

	
	
	cin >> V >> E;
	
	for(int i = 0 ; i < E ; i ++){
		cin >> x >> y >> d;
		a[x].push_back(make_pair(d, y));
		b[y].push_back(make_pair(d, x));
		inDegree[y]++;
	}
	
	
	cin >> start >> finish;
	search(start, finish);
	return 0;
}
