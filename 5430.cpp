#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	deque<int> dq;
	cin >> t;
	while(t--){
		int direction = 0; // 0 : 정방향 , 1: 역방향 
		bool ignore = false;
		char s[100001];
		cin >> s; // 명령어 입력 
		int _size;
		cin >> _size; // 배열의 크기 입력 
		char c;
		int n;
		for(int i = 0 ; i < _size ; i ++){
			cin >> c >> n;
			dq.push_back(n);
		}//배열입력 
		cin >> c;
		if(_size == 0){
			cin >> c;
		}
		for(int i = 0 ; s[i] != '\0' ; i ++){
			if(s[i] == 'R'){
				if(direction == 0){
					direction = 1;
				}
				else{
					direction = 0;
				}
			}
			else{
				if(dq.empty()){ // D인데 배열이 비어있을 때 
					ignore = true;
					cout << "error\n";
					break;
				}
				else{ // D이고 배열이 비어있지 않을 때 
					if(direction == 1){
						dq.pop_back();
					}
					else{
						dq.pop_front();
					}
				}
			}
		}
		if(!ignore){
			cout << '[';
			while(!dq.empty()){
				if(direction == 1){
					if(dq.size()!=1){
						cout << dq.back() << ',';
					}
					else{
						cout << dq.back();
					}
					dq.pop_back();
				}
				else{
					if(dq.size()!=1){
						cout << dq.front() << ',';
					}
					else{
						cout << dq.front();
					}
					dq.pop_front();
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}
