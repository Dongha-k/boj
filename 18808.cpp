#include <iostream>
#include <vector>

int n, m, s;// 노트북 세로 길이, 가로 길이, 스티커 수 
int place[40][40]; // 노트북
int a[100][10][10]; // 스티커 번호, 세로, 가로 
vector<int> degree[100]; // 스티커 각도
vector<pair<int, int>> sizeOfSticker; // 스티커 세로 가로 크기정보 

bool rotate(int number, int deg){ // 스티커 번호, 회전할 각도 
	
}


int main(){
	int sn, sm;
	cin >> n >> m >> s;
	
	for(int i = 0 ; i < s ; i ++){
		cin >> sn >> sm;
		sizeOfSticker[i].push_back(make_pair(sn, sm));
		
		for(int j = 0 ; j < sn ; j ++){
			for(int k = 0 ; k < sm ; k ++){
				cin << a[i][j][k];
			}
		}
		degree[i].push_back(0, 90, 180, 270);
		
	}
	return 0;
}
