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
		if(!state){ // 균형이 안맞을 시 다음 입력을 위해 스택에 있는 데이터 비우기 
			while(!s.empty()){
				s.pop();
			}
		}
		else{ // state 가 true인 경우 
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
