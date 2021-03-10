#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int _time[10001]; // �ǹ��� ���µ� �ɸ��� �ð� 
int result[10001]; // result[i] : �ǹ� i���� ���µ� �ɸ��� �ּ� �ð� 
int inDegree[10001] = {0, }; // ��������
vector<int> adj[10001]; // ������� 
int t; // �׽�Ʈ ���̽� ����
int n; // �ǹ��� ����
int k; // �Ǽ� ���� ��Ģ ����
void func(){
	queue<int> q;
	for(int i = 1 ; i <= n ; i ++){ 
		if(inDegree[i] == 0) {
			q.push(i);
			result[i] = _time[i]; 
		}	
	} // ���� ó���� ���� ������ 0�� ������ ť�� ���� 
	for(int i = 0 ; i < n ; i ++){ // �� ��忡 ���ؼ��� �ѹ��� ó�����ָ� �Ǵϱ� n���� ���� 
		int x = q.front();
		q.pop();
		for(int y : adj[x]){
			if(result[y] < result[x] + _time[y]){
				result[y] = result[x] + _time[y];
			}
			if(--inDegree[y] == 0){
				q.push(y);
			}
		}
	}
}
int main(){
	cin >> t; // �׽�Ʈ ���̽� ���� �Է�
	while(t--){
		cin >> n >> k;
		// ��������, ����� �ʱ�ȭ, ������� �ʱ�ȭ 
		for(int i = 1 ; i <= n ; i ++){
			inDegree[i] = 0;
			result[i] = 0;
			adj[i].clear();
		}
		for(int i = 1 ; i <= n ; i ++){
			cin >> _time[i];
		}
		while(k--){
			int x, y;
			cin >> x >> y; // y�� ��������� ���� x�� ����������� 
			inDegree[y]++; // y�� �������� ++
			adj[x].push_back(y); // x�� ������忡 ���� 
		}
		int w;
		cin >> w;
		func();
		cout <<result[w] << '\n';
	}
	return 0;
}
