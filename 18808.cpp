#include <iostream>
#include <vector>

int n, m, s;// ��Ʈ�� ���� ����, ���� ����, ��ƼĿ �� 
int place[40][40]; // ��Ʈ��
int a[100][10][10]; // ��ƼĿ ��ȣ, ����, ���� 
vector<int> degree[100]; // ��ƼĿ ����
vector<pair<int, int>> sizeOfSticker; // ��ƼĿ ���� ���� ũ������ 

bool rotate(int number, int deg){ // ��ƼĿ ��ȣ, ȸ���� ���� 
	
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
