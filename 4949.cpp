#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(){
	char text[101];
	bool state;
	
	while(true){
		cin.getline(text, 101);

		if(!strcmp(text, ".")){
			return 0;
		}
		
		state = true;
		stack<char> s;
		
		for(int i = 0 ; text[i] != '\0' ; i ++){
			if(text[i] == '[' or text[i] == '('){
				s.push(text[i]);
			}
			else if(text[i] == ']'){
				if(s.empty()){
					cout << "no\n";
					state = false;
					break;
				}
				else if(s.top() == '['){
					s.pop();
				}
				else{
					cout << "no\n";
					state = false;
					break;
				}
			}
			else if(text[i] == ')'){
				if(s.empty()){
					cout << "no\n";
					state = false;
					break;
				}
				else if(s.top() == '('){
					s.pop();
				}
				else{
					cout << "no\n";
					state = false;
					break;
				}
			}	
		}
		if(!state){ // ������ �ȸ��� �� ���� �Է��� ���� ���ÿ� �ִ� ������ ���� 
			while(!s.empty()){
				s.pop();
			}
		}
		else{ // state �� true�� ��� 
			if(!s.empty()){
				cout << "no\n";
				while(!s.empty()){
					s.pop();
				}
			} else{
				cout << "yes\n";
			}
		}
		
	}
	return 0;
}
