#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, back;
	queue<int> q;
	cin >> t;
	while(t--){
		string cmd;
		cin >> cmd;
		if(!cmd.compare("push")){
			int x;
			cin >> x;
			q.push(x);
			back = x;
		}
		else if(!cmd.compare("pop")){
			if(q.empty()) cout << "-1\n";
			else{
				cout << q.front() <<'\n';
				q.pop();
			}
		}
		else if(!cmd.compare("size")){
			cout << (int)q.size() << '\n';
		}
		else if(!cmd.compare("front")){
			if(!q.empty())cout << q.front() << '\n';
			else cout << "-1\n"; 
		}
		else if(!cmd.compare("back")){
			if(q.empty()) cout << "-1\n";
			else cout << back << '\n';
		}
		else if(!cmd.compare("empty")){
			if(q.empty()) cout <<"1\n";
			else cout <<"0\n";
		}
		
	}
	return 0;
}
