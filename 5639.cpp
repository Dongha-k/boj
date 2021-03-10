#include <iostream>
#include <set>
using namespace std;
int main(){
	set<int> nums{1,2,3,4,5};
	for(int num : nums){
		cout << num << ' ';
	}
	return 0;
}
