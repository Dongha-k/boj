#include <bits/stdc++.h>
using namespace std;

int d[100001];// d[i] : 0��°���� i��° �������� �� 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	 
	int n, m; // n: ���� ����, m: �׽�Ʈ ���̽� �ټ� 
	cin >> n >> m;
	
	d[0] = 0;
	int a;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a;
		d[i] = d[i-1] + a;
	}
	
	
	int first, end;	
	for(int i = 0 ; i < m ; i++){
		cin >> first >> end;		
		cout <<d[end] - d[first - 1]  << '\n';
	}
	return 0;
}
