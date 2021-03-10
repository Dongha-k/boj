#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	string s;
	int result = 0;
	stack<char> st;
	cin >> s;
	for(int i = 0 ; s[i] != '\0' ; i ++){
		if(s[i] == '('){
			st.push(s[i]);
		}
		else{
			st.pop();
			if(s[i-1] == '('){
				result += st.size();
			}
			else{
				result ++;
			}
		}
	}
	cout << result;
	return 0;
}
