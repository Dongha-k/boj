#include <iostream>
using namespace std;
int main(){
	char a[6];
	
	while(true){
		cin >> a;
		if(a[0] == '0'){
			return 0;
		}
		int length, flag = false;
		for(length = 0 ; a[length] != '\0' ; length ++){}
		
		for(int i = 0 ; i < length / 2 ; i ++){
			if(a[i] != a[length - i -1 ]){
				cout << "no\n";
				flag = true;
				break;
			}
		}
		if(!flag){
			cout << "yes\n";
		}
	}
	return 0;
}
