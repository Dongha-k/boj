#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> p;
vector<p> v;
bool check[200000] = {false, };
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		int first, end;
		cin >> first >> end;
		v.push_back({end, first});
	}
	sort(v.begin(), v.end()); // ȸ�ǰ� ���� ������ ������ ����
//	for(auto u : v){
//		cout << u.second <<" ~ "<< u.first << '\n';
//	}
//	cout << "\n\n\n";
//	 
	int cnt = 0;
	int t = 0;
	for(int i = 0 ;i < v.size() ; i ++){
		if(t > v[i].second) continue;
		// ȸ���� ���۽ð���  
		cnt++;
		t = v[i].first;
	}
	cout << cnt ;	 
	return 0;
}
