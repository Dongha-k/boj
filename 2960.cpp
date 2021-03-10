#include <iostream>
using namespace std;

int main(){
	int n, k;
	bool isErased[1001];
	int count = 0;
	
	
	cin >> n >> k;
	for(int i =2 ; i <= n ; i ++){
		isErased[i] = false;
	}
	
	for(int i =2; i <= n; i ++){
		if(!isErased[i]){
			for(int j = i ; j <= n ; j += i){
				if(!isErased[j]){
					count ++;
					if(k == count){ 
						cout << j;
						return 0;
					}
					else{	
						isErased[j] = true;
					}
				}
			}
		}
	}

	return 0;
}
