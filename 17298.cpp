#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> idx[1000001];
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	vector<int> answer;
	stack<int> s;
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		answer.push_back(-1);
		int x;
		cin >> x; 
		while(!s.empty()){
			if(s.top() >= x) break;
			// s.top() < x �ΰ�� ��ū���� ������ ��ġ�� �������� 
			int y = s.top();
			for(int j = 0 ; j < idx[y].size() ; j ++){
				answer[idx[y][j]] = x;
				s.pop();
			}
			idx[y].clear();
		}
		idx[x].push_back(i); // x�� ��ġ�� ���
		s.push(x);
	}
	for(int i = 0 ; i < n ; i ++){
		cout << answer[i] << ' ';
	}
	return 0;
}
