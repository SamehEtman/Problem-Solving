#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;
int main() {
	int n , d , r;
	while (scanf("%d %d %d" , &n , &d , &r) , n , d ,r){
		int morning[n];
		int evening [n];
		for (int i = 0 ; i < n;i++) scanf("%d" , &morning[i]);
		for (int i = 0 ; i < n;i++) scanf("%d" , &evening[i]);
		sort(morning , morning + n);
		sort(evening , evening + n);
		reverse(evening , evening + n);
		int ans = 0;
		for (int i = 0 ; i < n;i++){
			if (morning[i] + evening[i] > d){
				ans+= (morning[i] + evening[i] - d) * r;
			}
		}
		printf("%d\n" , ans);
	}
	return 0;
}
