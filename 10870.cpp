#include <stdio.h>

int d[21];


int fibo(int n){
	if(d[n] != 0) return d[n];
	else if(n == 0) return 0;
	else if(n == 1) return 1;
	else return d[n] = fibo(n-1) + fibo(n-2); 
}


int main(){
	int number;
	scanf("%d", &number);
	printf("%d", fibo(number));
	return 0;
}
