#include <iostream>
using namespace std;
double slope(int x1, int y1, int x2, int y2){
	double result = (double)(y1 - y2) / (x1-x2);
	return result; 
}
/*
	**result < 0 : j의 빌딩이 더 낮게 있음 
	**result == 0 : 두 빌딩의 높이가 같음 
	**result > 0 : j빌딩이 더 높음 
*/
int main(){
	int n;
	int b[50];
	cin >> n;
	for(int i = 0 ; i < n ; i ++){
		cin >> b[i]; // 빌딩들의 높이를 입력 받는다. 
	}
	int _max = 0;
	for(int i = 0 ; i < n ; i ++){
//		cout << i << " 번째 건물 : 왼쪽 ";
		int cnt = 0;
		double max_slope = -1000000001; 
		for(int j = i-1 ; j >= 0 ; j --){
			double grad = -slope(i,b[i],j,b[j]); //j가 더 왼쪽에 있을 때 i 위치와 j위치에 있는 빌딩의 슬로프를 구함
			if(max_slope >= grad){ // max_slope가 더 크면 j빌딩은 보지 못함
				continue;
			}
			else{//슬로프가 max_slope보다 큰 경우 
//				cout << b[j] << ' ';
				max_slope = grad; // 최대 값 갱신 
				cnt ++; // j에 위치한 건물을 i건물에서 볼 수 있으므로 카운팅해줌 
			}
		}
//		cout << " 오른쪽 ";
		max_slope = -1000000001; 
		for(int j = i+1 ; j < n ; j ++){
			double grad = slope(j, b[j], i , b[i]);
			if(max_slope >= grad){ // max_slope가 더 크면 j빌딩은 보지 못함
				continue;
			}
			else{//슬로프가 max_slope보다 큰 경우 
//				cout << b[j] << ' ';
				max_slope = grad; // 최대 값 갱신 
				cnt ++; // j에 위치한 건물을 i건물에서 볼 수 있으므로 카운팅해줌 
			}			
		}
		_max = max(_max, cnt);
//		cout << " -> " << cnt << '\n'; 
	}
	cout << _max;
	return 0;
}
