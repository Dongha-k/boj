#include <iostream>
#include <string>
bool used[51] = {false, };
int max_num;
using namespace std;
int main(){
	string s;
	cin >> s;
	if(s.size() < 10) max_num = s.size();
	else max_num = 5 + (s.size()-1)/2;
	
	return 0;
}
