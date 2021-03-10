#include <iostream>
using namespace std;
int dis(int x1, int y1, int x2, int y2){ // 좌표 사이의 거리의 제곱 값 리턴
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
			cout << -1 << '\n'; // 중심이 같고 반지름도 같을 때 
		}
		else if(x1 == x2 && y1 == y2){
			cout << 0 << '\n'; // 중심이 같고 작은원이 큰원안에 있을 때 
		}
		else if((r1 - r2) * (r1 - r2) > distance){
			cout << 0 << '\n'; // 작은 원이 큰 원안에 들어있을 때 
		}
		else if((r1 - r2) * (r1 - r2) == distance){
			cout << 1 << '\n'; // 내접할 때 
		}
		else if((r1 - r2) * (r1 - r2) < distance and (r1 + r2) * (r1 + r2) > distance){
			cout << 2 << '\n'; // 겹치면서 두개점 교차 
		}
		else if((r1 + r2) * (r1 + r2) > distance){
			cout << 2 << '\n'; // 겹치면서 두개점 교차할 때 
		}
		else if((r1 + r2) * (r1 + r2) < distance){
			cout << 0 << '\n'; // 원이 서로 떨어져있을 때 
		}
		else if((r1 + r2) * (r1 + r2) == distance){
			cout << 1 << '\n'; // 외접할 때
		}
		else{
			cout << 2 << '\n'; 
		} 
	}
	return 0;
}
