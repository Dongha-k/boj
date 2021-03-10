#include "bits/stdc++.h"
using namespace std;
int arr[10][10];
vector<pair<int, int> > zeroPoint; // ��ĭ�� ��ǥ�� ������� ���� 
vector<int> zeroArrays[81]; // ��ĭ�� ������ �� �ִ� ������ ���� 
bool checkNumber[10];
int flag = 0;
bool check(){ // ��ü ������ ĭ�� ��ĭ���� �� ä������ �� �����̵Ǵ��� üũ 
	int count = 0;
	for(int x = 1 ; x<= 9 ; x ++){
		for(int i = 1 ; i <= 9 ; i ++){ // ���ο� üũ 
			for(int j = 1; j <= 9 ; j ++){
				if(arr[x][j] == i) count ++;
			}
			if(count > 1){
				return false;
			}
			count = 0;
		}
	}
	for(int y = 1 ; y <= 9 ; y ++){
		for(int i = 1 ; i <= 9 ; i ++){ // ���� �� üũ 
			for(int j = 1; j <= 9 ; j ++){
				if(arr[j][y] == i) count ++;
			}
			if(count > 1){
				return false;
			}
			count = 0;
		}
	}
	
	for(int x = 1 ; x<= 9 ; x +=3){ // �� ���� üũ 
		for(int y = 1 ; y <= 9 ; y +=3){
			// �� ����			 
			for(int n = 1 ; n <= 9 ; n ++){
				for(int i = x ; i <= x + 2 ; i ++){
					for(int j = y ; j <= y + 2 ; j ++){
						if(arr[i][j] == n) count ++;
					}
				}
				if(count > 1){
					return false;
				}
				count = 0;
			}
			 
		}
	}
	return true; // ����, ����, ������ ��� ����ϸ� true ���� 
}
void f(int k){
	if(flag == 1){
		return;
	}
	if(k == zeroPoint.size()){
		if(check()){
			flag = 1; // ���� ó�� ���� ���� ���̽��� ���̱⋚���� 
			for(int i = 1 ; i <= 9 ; i++){
				for(int j = 1 ; j <= 9 ; j ++){
					cout << arr[i][j] << " ";
				}
				cout << "\n";
			}
			return;
		}
		else{
			return;
		}
	}
	
	for(int i = 0 ; i < zeroArrays[k].size() ; i ++){
		if(check()){
			arr[zeroPoint[k].first][zeroPoint[k].second] = zeroArrays[k][i];
			f(k+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);

	for(int i = 1 ; i <= 9 ; i ++){
		for(int j =1 ; j <= 9 ; j ++){
			cin >> arr[i][j];
			if(arr[i][j] == 0){
				zeroPoint.push_back({i, j}); // 0���� �Էµ� ������ ��ǥ�� ����
			}
		}
	}
	
	
	for(int i = 0 ; i < zeroPoint.size() ; i ++){
		int x = zeroPoint[i].first;
		int y = zeroPoint[i].second;
		for(int j = 1 ; j <= 9 ; j++){
			checkNumber[j] = true;
		}
		
		for(int c = 1 ; c <= 9 ; c ++){ // ����, ���η� ������ ��� ���� 
			checkNumber[arr[x][c]] = false;
			checkNumber[arr[c][y]] = false;
		}
		for(int c = 3*((x-1)/3) + 1 ; c <= 3*((x-1)/3) + 3 ; c ++){ // ���簢�� �������� ������ ��� ���� 
				for(int r = 3*((y-1)/3) + 1 ; r <= 3*((y-1)/3) + 3 ; r++){
					checkNumber[arr[c][r]] = false;				
				}
			}
		for(int a = 1 ; a <= 9 ; a++){
			if(checkNumber[a]){
				zeroArrays[i].push_back(a);
			}
		}
	}
//	for(int i = 0 ; i < zeroPoint.size() ; i ++){
//		cout << zeroPoint[i].first << ", " << zeroPoint[i].second << " : ";
//		for(int j = 0 ; j < zeroArrays[i].size() ; j ++){
//			cout << zeroArrays[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	f(0);
	return 0;
}
/*
0 5 2 0 0 7 0 9 8
1 0 6 0 5 8 0 0 4
0 0 0 0 1 0 7 0 0
0 6 0 0 0 3 2 1 0
0 0 8 1 0 5 6 0 0
0 1 9 6 0 0 0 3 0
0 0 3 0 4 0 0 0 0
6 0 0 2 8 9 0 0 0
9 2 0 7 0 0 4 8 0
*/
