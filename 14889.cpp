#include <iostream>
using namespace std;
int s[20][20], n;
bool visited[20];
int result[20], result2[20];
int sum1, sum2;
int _min = 10000000;
int cal(int p[]){
	int sum = 0;
	for(int i = 0 ;i < n/2 ; i ++){ // ������ ��ȣ�� ���� ���� 
		for(int j = 0 ; j < n/2 ; j ++){ //������ȣ�� ���յ� �ɷ�ġ�� ���� 
			sum += s[p[i]][p[j]];
		}
	}
	return sum;
}
void f(int k){
	if(k == n/2){
		for(int i = 0 ; i < n/2 - 1 ; i ++){
			if(result[i+1] < result[i]) return;
		}
		int cnt = 0;
		sum1 = cal(result);
		for(int i = 0; i < n ; i ++){
			bool check = true;
			for(int j = 0 ; j < n/2 ; j ++){
				if(i == result[j]){
					check = false;
					break;
				}
			}
			if(check){
				result2[cnt++] = i;
			}
		}
		sum2 = cal(result2);
		if(sum2 == sum1){
			_min = 0;
		}
		else if(sum2 > sum1){
			_min = min(_min, sum2 - sum1);
		}
		else{
			_min = min(_min, sum1 - sum2);
		}
	}
	else{
		for(int i = 0 ; i < n ; i ++){
			if(!visited[i]){
				result[k] = i;
				visited[i] = true;
				f(k+1);
				visited[i] = false;
			}
		}
	}
}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++){
			cin >> s[i][j];
		}
	}
	f(0);
	cout << _min;
	return 0;
}
