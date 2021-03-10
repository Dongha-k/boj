#include <iostream>
#include <string>
#include <vector>
using namespace std;
char sign[11];
int result[11];
bool used[10] = {false, };
int len;
vector<string> v;
void f(int k){
	if(k == len + 1){
		string s = "";
		for(int i = 0 ; i <= len ; i ++){
			s += result[i] +'0';
		}
		v.push_back(s);
	}
	else{
		for(int i = 9 ; i >= 0 ; i --){
			if(k == 0){
				result[k] = i;
				used[i] = true;
				f(k+1);
				used[i] = false;
			}
			else if(sign[k-1] == '<'){
				if(used[i]) continue;
				if(result[k-1] < i){
					used[i] = true;
					result[k] = i;
					f(k+1);
					used[i] = false;
				}
			}
			else{
				if(used[i]) continue;
				if(result[k-1] > i){
					used[i] = true;
					result[k] = i;
					f(k+1);
					used[i] = false;
				}
			}
		}
	}
}
int main(){
	cin >> len;
	for(int i = 0 ; i < len ; i ++){
		cin >> sign[i];
	}
	f(0);
	cout << v[0] << '\n' << v[v.size() -1];
	return 0;
}
