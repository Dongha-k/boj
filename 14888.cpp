#include <iostream>
#include <vector>
using namespace std;
// ������ ���� �ٽô� ��Ǭ��... 
int numbers[20]; // �ǿ����ڵ�
vector<int> op; // �����ڵ�
bool used[20] = {false,};
long long result = 0;
int arr[20];
long long _max = -1000000001;
long long _min = 1000000001;
int n; // �ǿ������� ����
void f(int k){
	if(k == n){
		for(int i = 1 ; i <= op.size() ; i ++){
			if(arr[i] == 0) result += numbers[i];
			else if(arr[i] == 1) result -= numbers[i];
			else if(arr[i] == 2) result *= numbers[i];
			else result /= numbers[i];
//			cout << arr[i] << ' ';
		}
//		cout << '\n';
		_min = min(_min, result);
		_max = max(_max, result);
		result = numbers[0];
	}
	else{
		for(int i = 0 ; i < op.size() ; i ++){
			if(!used[i]){ // i���� �����ڸ� ����� ���� �������� 
				used[i] = true; // i��° �����ڸ� ����ϰ��� 
				arr[k] = op[i];
				f(k+1);
				used[i] = false;
			}
		}
	}
}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		cin >> numbers[i];
	}
	for(int i = 0 ;i < 4; i ++){
		int x;
		cin >> x;
		for(int j = 0 ; j < x ; j ++){
			op.push_back(i);
		}
	}
	result = numbers[0];
	f(1);
	cout << _max << '\n' <<_min;
	return 0;
}
