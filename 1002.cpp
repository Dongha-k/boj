#include <iostream>
using namespace std;
int dis(int x1, int y1, int x2, int y2){ // ��ǥ ������ �Ÿ��� ���� �� ����
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); 
}
int main(){
	int t;
	int x1, y1, r1;
	int x2, y2, r2;
	cin >> t;
	while(t--){
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int distance = dis(x1, y1, x2, y2);
		if(x1 == x2 && y1 == y2 && r1 == r2){
			cout << -1 << '\n'; // �߽��� ���� �������� ���� �� 
		}
		else if(x1 == x2 && y1 == y2){
			cout << 0 << '\n'; // �߽��� ���� �������� ū���ȿ� ���� �� 
		}
		else if((r1 - r2) * (r1 - r2) > distance){
			cout << 0 << '\n'; // ���� ���� ū ���ȿ� ������� �� 
		}
		else if((r1 - r2) * (r1 - r2) == distance){
			cout << 1 << '\n'; // ������ �� 
		}
		else if((r1 - r2) * (r1 - r2) < distance and (r1 + r2) * (r1 + r2) > distance){
			cout << 2 << '\n'; // ��ġ�鼭 �ΰ��� ���� 
		}
		else if((r1 + r2) * (r1 + r2) > distance){
			cout << 2 << '\n'; // ��ġ�鼭 �ΰ��� ������ �� 
		}
		else if((r1 + r2) * (r1 + r2) < distance){
			cout << 0 << '\n'; // ���� ���� ���������� �� 
		}
		else if((r1 + r2) * (r1 + r2) == distance){
			cout << 1 << '\n'; // ������ ��
		}
		else{
			cout << 2 << '\n'; 
		} 
	}
	return 0;
}
