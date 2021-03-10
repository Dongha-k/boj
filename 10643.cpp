#include <iostream>
using namespace std;
int main(){
	int pizza[8];
	for(int i = 0 ; i < 8 ; i ++){
		cin >> pizza[i];
	}
	int sum = 0;
	int _max = 0;
	for(int i = 0 ; i < 4 ; i ++){
		sum += pizza[i];
	}
	_max = sum;
	for(int i =  4; i < 8 + 3 ; i ++){
		sum += pizza[i%8] - pizza[i-4];
		
		_max = max(_max, sum);
	}
	
	cout << _max;
}
