#include "bits/stdc++.h"
using namespace std;
int n, m;
int place[8][8];
int result[8][8];
bool flag = false;
vector<tuple<int, int, int> > cctvPos; // cctv x��ǥ, y��ǥ, cctv��ȣ
int cctv[6][4] = {
	{},
	{1, 2, 3, 4},
	{13, 24},
	{12, 23, 34, 41},
	{123, 234, 341, 124},
	{1234}
};
int length[6] = {0, 1, 2, 2, 3, 4};
int candidate[6] = {0, 4, 2, 4, 4, 1}; // �ĺ����� ���� 
int temp[4];
vector<int> selected;
int answer = 10000;
void rotate(tuple<int, int, int> c, int d){ //c : cctv ���� , d : ���� ����
	
	int x, y, number;
	tie(x, y, number) = c;
//	cout << "rotate ���� ... " << d <<  " / "  ;
	
	int direction = cctv[number][d];
	int cnt = length[number] - 1;
	
	while(d!= 0){
		temp[cnt--] = d%10;
		d /= 10;
	}
	
	//temp ����
	
//	cout <<"[";
//	for(int i = 0 ; i < length[number] ; i ++){
//		cout << temp[i] << ' ';
//	} 
//	cout << "]  ����.. " << endl;
//	
	
	
	
	
	// temp ������ �� ������ ���
	for(int i = 0 ; i < length[number] ; i ++){
		if(temp[i] == 1){ // ���������� 
			for(int j = y ; j < m ; j ++){
				if(result[x][j] == 6){ // ���� ������ �Ǹ� �� 
					break;
				}
				else if(result[x][j] != 0){ // cctv�� ġ�ԵǸ� continue;
					continue;
				}
				else{ // 0�� ġ�ԵǸ� ���ÿ���ǥ�� 
					result[x][j] = '#';
				}
			}
		}
		else if(temp[i] == 2){ // �������� 
			for(int j = x ; j >= 0 ; j --){
				if(result[j][y] == 6){
					break;
				}
				else if(result[j][y] != 0){
					continue;
				}
				else{
					result[j][y] = '#';
				}
			}
		}
		else if(temp[i] == 3){ // �������� 
			for(int j = y ; j >= 0 ; j --){
				if(result[x][j] == 6){
					break;
				}
				else if(result[x][j] != 0){
					continue;
				}
				else{
					result[x][j] = '#';
				}
			}
		}
		else{ // �Ʒ��� 
			for(int j = x ; j < n;  j++){
				if(result[j][y] == 6){
					break;
				}
				else if(result[j][y] != 0){
					continue;
				}
				else{
					result[j][y] = '#';
				}
			}
		}
	}
}


void bf(int k){
	if(flag){
		return;
	}
	if(k == cctvPos.size()){
		 for(int i = 0 ; i < n ; i ++){
		 	for(int j = 0 ; j < m ; j ++){
		 		result[i][j] = place[i][j];
			 }
		 }
		 
		for(int i  = 0 ; i < k ; i ++){
		 	
			rotate(cctvPos[i], cctv[get<2>(cctvPos[i])][selected[i]]);
		}
		int count = 0 ;
		for(int i = 0 ; i < n ; i ++){
			for(int j = 0 ; j < m ; j ++){
				if(result[i][j] == 0) count ++;
//				if(result[i][j] != '#'){
//				cout << result[i][j] << " ";
//				}
//				else{
//					cout << "# ";
//				}
			}
//			cout << "\n";
		}
//		cout << '\n';
		answer = (count < answer)? count : answer;
//		cout << "������� �ּ�  : " <<answer << endl;
		if(answer == 0) flag = true;
		return;
	}
	for(int i = 0 ; i < candidate[get<2>(cctvPos[k])] ; i ++){
		selected.push_back(i); 
		bf(k+1);
		selected.pop_back();

	}
} 


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int x = 0 ; x < n ; x ++){
		for(int y = 0 ;  y < m ; y ++){
			cin >> place[x][y];
			if(1 <= place[x][y] and place[x][y] <= 5){
				cctvPos.push_back(make_tuple(x, y, place[x][y]));
			}
		}
	}
	
	
	bf(0);
	cout << answer;

	return 0;
}
