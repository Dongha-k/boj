#include <iostream>
using namespace std;
int arr[1000001];
int temp[1000001];
void f(int first, int last){ 
	if(first >= last){
		return;
	}
	int mid = (first + last) / 2;
	f(first, mid);
	f(mid + 1, last);
//	for(int i = first ; i <= mid ; i ++){
//		cout << arr[i] << ' ';
//	}
//	cout << " / ";
//	for(int i = mid + 1 ; i <= last ; i ++){
//		cout << arr[i] << ' ';
//	}
//	cout << '\n';
	int l = first , r = mid + 1;
	for(int i = first ; i <= last ; i++){
		if(l > mid){
			temp[i] = arr[r++];
		}
		else if(r > last){
			temp[i] = arr[l++];
		}
		else if(arr[l] < arr[r] and l <= mid){
			temp[i] = arr[l++];
		}
		else if(arr[l] > arr[r] and r <= last){
			temp[i] = arr[r++];
		}
	}
	for(int i = first ; i <= last ; i ++){
		arr[i] = temp[i];
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		cin >> arr[i];
	}
	f(0, n-1);
	for(int i = 0 ; i < n ; i ++){
		cout << arr[i] << '\n';
	}
	return 0;
}
