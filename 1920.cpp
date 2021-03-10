#include <iostream>
#include <set>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	set<int> s;
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		int x; cin >> x;
		s.insert(x);
	}
	int m;
	cin >> m;
	for(int i = 0 ; i < m ; i ++){
		int y;
		cin >> y;
		if(s.find(y) == s.end()){
			cout<< 0 << '\n';
		}
		else{
			cout << 1 << '\n';
		}
	}
	return 0;
}
