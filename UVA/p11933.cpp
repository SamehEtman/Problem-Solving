#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <bitset>
#include <limits>
#include <set>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n), n) {
		bitset<32> x(n);
		int k = 0;
		stack <int>a;
		stack <int>b;
		for (int i = 0 ; i < 32;i++){
			if (x[i] == 1 && k%2 ==0){
				a.push(1);
				b.push(0);
				k++;
			}else if (x[i] == 1 && k%2 ==1){
				a.push(0);
				b.push(1);
				k++;
			}else {
				a.push(0);
				b.push(0);
			}
		}
		int n1 = 0 , n2 = 0;
		for (int i = 31 ;i >= 0 ;i--){
			n1+= a.top() *pow(2,i);
			n2+= b.top() *pow(2,i);
			a.pop();b.pop();
		}
		cout << n1 << " " << n2 <<endl;
	}
	return 0;
}
