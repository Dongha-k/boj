#include <iostream>
#include <algorithm>
using namespace std;
int l, c;
int cnt = 0; // ¸ðÀ½ °¹¼ö l - cnt = ÀÚÀ½ °¹¼ö 
char pw[16];
char result[16];
void f(int k){
	if(k == l){
		if(!(cnt >= 1 and l - cnt >= 2)) return; 
		cout << result << '\n';
		return;
	}
	else{
		for(int i = 0 ; i < c ; i ++){
			if(k == 0 || result[k-1] < pw[i]){
				result[k] = pw[i];
				if(result[k] == 'a' or result[k] == 'e'
				or result[k] == 'i' or result[k] == 'o'
				or result[k] == 'u') cnt ++; 
				f(k+1);
				if(result[k] == 'a' or result[k] == 'e'
				or result[k] == 'i' or result[k] == 'o'
				or result[k] == 'u') cnt --;
				result[k] = 0;
			}
		}
	}
	
}
int main(){
	cin >> l >> c;
	for(int i = 0 ; i < c ; i ++){
		cin >> pw[i];
	}
	sort(pw, pw+c);
	
	f(0);
	return 0;
}
