#include <iostream>
using namespace std;
double slope(int x1, int y1, int x2, int y2){
	double result = (double)(y1 - y2) / (x1-x2);
	return result; 
}
/*
	**result < 0 : j�� ������ �� ���� ���� 
	**result == 0 : �� ������ ���̰� ���� 
	**result > 0 : j������ �� ���� 
*/
int main(){
	int n;
	int b[50];
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		cin >> b[i]; // �������� ���̸� �Է� �޴´�. 
	}
	int _max = 0;
	for(int i = 0 ; i < n ; i ++){
//		cout << i << " ��° �ǹ� : ���� ";
		int cnt = 0;
		double max_slope = -1000000001; 
		for(int j = i-1 ; j >= 0 ; j --){
			double grad = -slope(i,b[i],j,b[j]); //j�� �� ���ʿ� ���� �� i ��ġ�� j��ġ�� �ִ� ������ �������� ����
			if(max_slope >= grad){ // max_slope�� �� ũ�� j������ ���� ����
				continue;
			}
			else{//�������� max_slope���� ū ��� 
//				cout << b[j] << ' ';
				max_slope = grad; // �ִ� �� ���� 
				cnt ++; // j�� ��ġ�� �ǹ��� i�ǹ����� �� �� �����Ƿ� ī�������� 
			}
		}
//		cout << " ������ ";
		max_slope = -1000000001; 
		for(int j = i+1 ; j < n ; j ++){
			double grad = slope(j, b[j], i , b[i]);
			if(max_slope >= grad){ // max_slope�� �� ũ�� j������ ���� ����
				continue;
			}
			else{//�������� max_slope���� ū ��� 
//				cout << b[j] << ' ';
				max_slope = grad; // �ִ� �� ���� 
				cnt ++; // j�� ��ġ�� �ǹ��� i�ǹ����� �� �� �����Ƿ� ī�������� 
			}			
		}
		_max = max(_max, cnt);
//		cout << " -> " << cnt << '\n'; 
	}
	cout << _max;
	return 0;
}
