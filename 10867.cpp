#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	bool arr[2001] = {false, }; // 0 ~ 1000 : 양의 정수 , 1001 ~ 2000 음의 정수
	for(int i = 0 ; i < n ; i ++){
		int x;
		cin >> x;
		if(x >= 0) arr[x] = true;
		else arr[1000-x] = true;
	}
	for(int i = 2000 ; i > 1000 ; i--){
		if(arr[i]) cout << -(i - 1000) << ' ';
	}
	for(int i = 0 ; i <= 1000 ; i ++){
		if(arr[i]) cout << i << ' ';
	}
	
	return 0;
}
