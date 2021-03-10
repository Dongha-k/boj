#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001


using namespace std;

int V, E;
vector<pair<int, int> > a[MAX], b[MAX]; // b = ���������� �̵� 
int inDegree[MAX], result[MAX], c[MAX];
 


void search(int start, int finish){
	queue<int> q;
	// ������ ��带 ť�� ���� ���� 
	q.push(start);
	
	while(!q.empty()){ // �� ��庰 �Ӱ� �ð��� ���� = ������ ��忡������ �ɸ��� �ð� �� �ִ� �ð�(�Ÿ�)
		int x = q.front();
		q.pop();
		for(int i = 0 ; i < a[x].size() ; i ++){
			pair<int, int> y = make_pair(a[x][i].first, a[x][i].second);
			if(result[y.second] <= y.first + result[x]){
				result[y.second] = y.first + result[x];
			}
			// ���Ӱ� ���� ������ 0�� �� ������ ť�� ���� 
			if(--inDegree[y.second] == 0){
				q.push(y.second); 
			}
		}
	}
	
//	for(int i = 1 ; i <= V ; i ++){
//		cout << result[i] << " ";
//	}
	//����� �������� 
	int count = 0;
	q.push(finish);
	
	while(!q.empty()){
		int y = q.front();
		q.pop();
		for(int i = 0 ; i < b[y].size() ; i ++){
			pair<int, int> x = make_pair(b[y][i].first, b[y][i].second);
			// ���� ��ο� ���ԵǴ� �������� Ȯ��
			if(result[y] - result[x.second] == x.first) {
				count ++;				
				if(c[x.second] == 0){ // �湮ó�� 
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
