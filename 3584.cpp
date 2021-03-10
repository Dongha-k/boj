#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[10001];
int cX, cY;
int cnt = 0;
int depth = 0;
int _min;
int min_node;
bool firstCheck, secondCheck;
void dfs(int s){
	depth ++;
//	cout << s << ' ';
	if((s == cX or s == cY) and cnt == 0){
		cnt ++;
		if(s == cX) firstCheck = true;
		else secondCheck = true;
		_min = depth;
		min_node = s;
	}
	else if(cnt == 1 and (s == cX or s == cY)){
		if(s == cX and firstCheck){}
		else if(s == cY and secondCheck){}
		else{
			if(_min > depth){
				_min = depth;
				min_node = s;
			}
			cnt ++;
		}
	}
	else if(cnt == 1){
		if(_min > depth){
			_min = depth;
			min_node = s;
		}
	}
	for(auto u : adj[s]){
		dfs(u);
		depth --;
//		cout << s << ' ';
		if((s == cX or s == cY) and cnt == 0){
			cnt ++;
			if(s == cX) firstCheck = true;
			else secondCheck = true;
			_min = depth;
			min_node = s;
		}
		else if(cnt == 1 and (s == cX or s == cY)){
			if(s == cX and firstCheck){}
			else if(s == cY and secondCheck){}
			else{
				if(_min > depth){
					_min = depth;
					min_node = s;
				}
				cnt ++;
			}
		}
		else if(cnt == 1){
			if(_min > depth){
				_min = depth;
				min_node = s;
			}
		}
	}
}
int link[10001];
int find(int x){
	while(x!=link[x])x=link[x];
	return x;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		firstCheck = false;
		secondCheck = false;
		cnt = 0;
		int n; // 노드의 갯수 
		cin >> n;
		for(int i = 1 ; i <= n ; i ++){
			link[i] = i;
		}
		for(int i = 0 ; i < n - 1 ; i ++){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			link[y] = x;
		} // 인접노드 정보입력 
		cin >> cX >> cY;
		dfs(find(1));
		cout << min_node << '\n'; 
		for(int i = 0 ; i <= 10000 ; i ++){
			adj[i].clear();
		}
	}

	return 0;
}
