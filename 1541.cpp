#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
	cin >> s;
	int result = 0;
	bool minus = false;
	string temp = "";
	// 첫번째로 마이너스가 발생 한 이후로는 그 이후 입력 받은 정수를 결과에서 계속 뺴줌
	for(int i = 0 ; i < s.size() ; i ++){
		if(s[i] == '+' or s[i] == '-'){
			if(minus){
				result -= stoi(temp);
			}
			else{
				if(s[i] == '-'){
					result += stoi(temp);
					minus = true;
				}
				else{
					result += stoi(temp);
				}
				
			}
			temp = "";
		}
		else{
			temp += s[i];
		}
	}
	if(minus){
		result -= stoi(temp);
	}
	else{
		result += stoi(temp);
	}
	cout << result;
	return 0;
}
