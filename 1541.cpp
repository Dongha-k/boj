#include <iostream>
#include <string>
using namespace std;
string s;
int main(){
	cin >> s;
	int result = 0;
	bool minus = false;
	string temp = "";
	// ù��°�� ���̳ʽ��� �߻� �� ���ķδ� �� ���� �Է� ���� ������ ������� ��� ����
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
