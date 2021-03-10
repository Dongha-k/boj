#include <iostream>
using namespace std;
int main(){
	int left = 0, right = 0;
	int arr[10000];
	int n, m, cnt = 0;
	cin >> n >> m;
	for(int i = 0 ; i < n ; i ++){
		cin >> arr[i];
	}
	int sum = arr[0];
	while(right < n){
		if(sum < m){
			sum += arr[++right];
		}
		else if(sum > m){
			sum -= arr[left++];
		}
		else{ // if sum == m:
			cnt ++;
//			cout << left << ", " << right << "\n";
			sum += arr[++right];
		}
	}
	cout << cnt;
	return 0;
}
