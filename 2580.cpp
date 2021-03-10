#include "bits/stdc++.h"
using namespace std;
int arr[10][10];
vector<pair<int, int> > zeroPoint; // 빈칸인 좌표롤 순서대로 저장 
vector<int> zeroArrays[81]; // 빈칸에 놓아질 수 있는 수들을 나열 
bool checkNumber[10];
int flag = 0;
bool check(){ // 전체 스도쿠 칸이 빈칸없이 다 채워졌을 때 정답이되는지 체크 
	int count = 0;
	for(int x = 1 ; x<= 9 ; x ++){
		for(int i = 1 ; i <= 9 ; i ++){ // 가로열 체크 
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
		for(int i = 1 ; i <= 9 ; i ++){ // 세로 열 체크 
			for(int j = 1; j <= 9 ; j ++){
				if(arr[j][y] == i) count ++;
			}
			if(count > 1){
				return false;
			}
			count = 0;
		}
	}
	
	for(int x = 1 ; x<= 9 ; x +=3){ // 각 구간 체크 
		for(int y = 1 ; y <= 9 ; y +=3){
			// 한 구간			 
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
	return true; // 세로, 가로, 구간이 모두 통과하면 true 리턴 
}
void f(int k){
	if(flag == 1){
		return;
	}
	if(k == zeroPoint.size()){
		if(check()){
			flag = 1; // 가장 처음 나온 정답 케이스가 답이기떄문에 
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
				zeroPoint.push_back({i, j}); // 0으로 입력된 스도쿠 좌표를 저장
			}
		}
	}
	
	
	for(int i = 0 ; i < zeroPoint.size() ; i ++){
		int x = zeroPoint[i].first;
		int y = zeroPoint[i].second;
		for(int j = 1 ; j <= 9 ; j++){
			checkNumber[j] = true;
		}
		
		for(int c = 1 ; c <= 9 ; c ++){ // 가로, 세로로 가능한 경우 넣음 
			checkNumber[arr[x][c]] = false;
			checkNumber[arr[c][y]] = false;
		}
		for(int c = 3*((x-1)/3) + 1 ; c <= 3*((x-1)/3) + 3 ; c ++){ // 정사각형 구간으로 가능한 경우 넣음 
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
