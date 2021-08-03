#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <limits>
#include <set>
#include <iomanip>
using namespace std;
int n;
#define ull unsigned long long
ull eval(int coff[30], int i) {
	ull a = 0;
	ull currentn = 1;
	for (int j = 0; j <= n; j++) {
		a += coff[j] * currentn;
		currentn *= i;
	}
	return a;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cin >> n;
		int coff[30];
		ull an = 0;
		for (int i = 0; i <= n; i++) {
			scanf("%d" , &coff[i]);
		}
		int d, k;
		scanf("%d %d" , &d , &k);
		int td = 0, tk = 0;
		for (int i = 1;; i++) {
			an = eval(coff, i);
			td+=d;
			tk+=td;
			if (tk >=k){
				printf("%llu\n", an);;
				break;
			}
		}
	}
	return 0;
}
