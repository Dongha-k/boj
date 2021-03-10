#include <iostream>
using namespace std;
int main(){
	int n;
	int arr[100001];
	cin >> n;
	int sum = 0, _max = -1000;
	for(int i = 0 ; i < n ; i ++){
		cin >> arr[i];
	}
	for(int i = 0 ; i < n ; i ++){
		if(sum < 0){
			sum = arr[i];
		}
		else{//sum >= 0
			sum += arr[i];
		}
		_max = max(_max, sum);
	}
	cout <<_max;
	return 0;
}
