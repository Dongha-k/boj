#include <iostream>
using namespace std;
int main(){
	int n, k; // n : 행렬의 크기, k : k 번 째 값
	cin >> n >> k;
	int first = 1, last = n;
	int mid = 0;
	int result = 0;
	while(first <= last){
		mid = (first + last)/2;
		if(mid * mid == k){
			result = mid;
			break;
		}
		else if(mid * mid < k) first = mid + 1;
		else last = mid - 1;
	}
	if(result == 0) result = mid;
	cout << result;
	return 0;
}
