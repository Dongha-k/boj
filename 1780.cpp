#include <iostream>
using namespace std;
int paper[3000][3000];
int result[3] = {0, }; // 1 0 -1
void search(int k, int x, int y){//k : 단계(길이), x: 시작x, y: 시작y 
	if(k == 1){
		if(paper[x][y] == 1) result[0] ++;
		else if(paper[x][y] == 0) result[1] ++;
		else result[2] ++;
		return;
	}
	else{
		int z = paper[x][y];
		bool flag = true;
		for(int i = x ; i < x + k ; i ++){
			for(int j = y ; j < y + k ; j ++){
				if(paper[i][j] != z){
					flag = false; // 하나라도 다른 숫자가 존재 
					break;
				}
			}
			if(!flag) break;
		}
		if(!flag){ // 9 구간으로 나눔 
			for(int i = x ; i < x + k ; i += k/3){
				for(int j = y ; j < y + k ; j+= k/3){
					search(k / 3, i, j);
				}
			}
		}
		else{
			if(z == 1) result[0] ++;
			else if(z == 0) result[1] ++;
			else result[2] ++;
			return;
		}
	}
	
	
}
int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++){
			cin >> paper[i][j];
		}
	}
	search(n, 0, 0);
	cout << result[2] << '\n' << result[1] <<'\n' <<result[0];
	
	return 0;
}
