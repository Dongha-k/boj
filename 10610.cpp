#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int sum = 0;
	bool zero = false;
	char s[100001];
	cin >> s;
	int i;
	for(i = 0 ; s[i]!='\0' ; i++){
		sum += s[i] - '0';
		if(s[i] == '0') zero = true;
	}
	if(zero and sum % 3 == 0){
		sort(s, s+i);
		reverse(s, s+i);
		for(int j = 0 ; j < i ; j ++){
			cout << s[j];
		}
	}
	else{
		cout << -1;
	}
	return 0;
}
