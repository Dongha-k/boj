#include <stdio.h>

int main(){
	int cnt[2001] = {0,}; // 0���� 1000������ ��� zone, 1001���� 2000���� ���� �� 
	int N;
	int M;
	
	scanf("%d", &N);
	for(int i =0 ; i < N ; i ++){
		scanf("%d", &M);
		if(M >= 0){
			cnt[M]++;
		} else{
			cnt[1000-M]++;
		}
	}
	
	for(int i = 2000 ; i >= 1001 ; i --){
		if(cnt[i] == 1){
			printf("-%d\n", i-1000);
		}
	}
	for(int i =0 ; i <= 1000 ; i ++){
		if(cnt[i] == 1){
			printf("%d\n", i);
		}
	}
	
	return 0;
}
