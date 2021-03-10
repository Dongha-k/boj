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
		cin >> time[i]; // �ش� �ǹ��� ���µ� �ɸ��� �ð� �Է�
		int x = 0;
		while(x != -1){
			cin >> x; // �ǹ��� �������� �ϼ��Ǿ������� �ǹ� ��ȣ �Է�
			if(x != -1){
				a[x].push_back(i);
				inDegree[i]++; // �ǹ� i�� ���� ���� ���� 
			}
		}
	}
	topologySort();
	
	for(int i = 1 ; i <= n ; i ++){
		cout << result[i] << endl;
	}
	
	return 0;
}
