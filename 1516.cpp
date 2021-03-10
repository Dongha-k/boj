#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int n, inDegree[501], time[501], result[501];
vector<int> a[501];

void topologySort(){
	queue<int> q;
	for(int i = 1 ; i <= n ; i ++){
		if(inDegree[i] == 0){
			result[i] = time[i];
			q.push(i);
		}
		
	}
	
	
	for(int i = 0 ; i < n ; i ++){
		int x = q.front();
		q.pop();
		
		for(int j = 0 ; j < a[x].size(); j ++){
			int y = a[x][j];
			result[y] = max(result[y], result[x] + time[y]);
			if(--inDegree[y] == 0){
				q.push(y);
			}
		}
	}
}


int main(){
	
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> time[i]; // 해당 건물을 짓는데 걸리는 시간 입력
		int x = 0;
		while(x != -1){
			cin >> x; // 건물을 짓기위해 완성되어져야할 건물 번호 입력
			if(x != -1){
				a[x].push_back(i);
				inDegree[i]++; // 건물 i의 진입 차수 높임 
			}
		}
	}
	topologySort();
	
	for(int i = 1 ; i <= n ; i ++){
		cout << result[i] << endl;
	}
	
	return 0;
}
