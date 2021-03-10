#include <iostream>
using namespace std;

int main(){
	unsigned int term[250001] = {0,};
	unsigned int result[250001] = {0,};
	
	int n, m, k;
	
	cin >> n >> m >> k;
	
	for(int i = 0 ; i <= n ; i ++){
		for(int j = 0 ; j <= n ; j ++){
			term[i+j]++;
		}
	}
	
	for(int i = 0 ; i < m ; i ++){
		for(int j = 0 ; term[j] != 0; j ++){
			result[i+j] += term[j]%1000000009;
		}
	}

	cout << result[k]%1000000009;
	return 0;
}
