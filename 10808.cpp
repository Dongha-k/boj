#include <iostream>
using namespace std;
int main(){
	char s[101];
	int cnt[27] = {0, };
	cin >> s;
	for(int i = 0 ; s[i] != '\0' ; i ++){
		cnt[s[i]-'a']++;
	}
	for(int i = 0 ; i < 26 ; i ++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
