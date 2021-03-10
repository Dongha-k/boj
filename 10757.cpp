#include <iostream>
#include <string>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a, b;
	string result;
	cin >> a >> b;
	int gap = a.size() - b.size();
	if(gap >= 0){
		string temp = "";
		for(int i = 0 ; i < gap ; i ++){
			temp += '0';
		}
		temp += b;
		int up = 0;
		for(int i = a.size() - 1 ; i >= 0 ; i --){
			if(up + a[i] - '0' + temp[i] -'0' < 10){
				result += up + a[i] - '0' + temp[i];
				up = 0;
			}
			else{ // 자릿수가 올라간 경우 
				result += (up + a[i] - '0' + temp[i] -'0')%10 + '0';
				up = 1;
			}
		}
		if(up == 1){
			result += '1';
		}
	}
	else{
		gap = -gap;
		string temp =  "";
		for(int i = 0 ; i < gap ; i ++){
			temp += '0';
		}
		temp += a;
		int up = 0;
		for(int i = b.size() - 1 ; i >= 0 ; i --){
			if(up + b[i] - '0' + temp[i] -'0' < 10){
				result += up + b[i] - '0' + temp[i];
				up = 0;
			}
			else{ // 자릿수가 올라간 경우 
				result += (up + b[i] - '0' + temp[i] -'0')%10 + '0';
				up = 1;
			}
		}
		if(up == 1){
			result += '1';
		}
	}
	
	
	for(int i = result.size()-1 ; i >= 0 ; i --){
		cout << result[i];
	}
	return 0;
}
