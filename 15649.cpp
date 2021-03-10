#include <iostream>

using namespace std;
int n, m; //입력으로 주어진 값
int arr[10]; // 나열할 수열들
bool isUsed[10] = {false, }; // 사용된 숫자인지 체크

void func(int k){ // k = 채워넣을 자릿수 
	if(k == m){
		for(int i = 0 ; i < m ; i++){
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	
	for(int i = 1 ; i <= n; i ++){
		if(!isUsed[i]){
			isUsed[i] = true;
			arr[k] = i;
			func(k+1);
			isUsed[i] = false;
		}
	}
}

int main(){
	cin >> n >> m;
	func(0);
	
	return 0;
}
