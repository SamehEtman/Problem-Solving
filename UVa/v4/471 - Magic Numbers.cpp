#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;
const long long MAXN = 9876543210;

bool check(long long num) {
	int vis[10] = { 0 };
	while (num) {
		if (vis[num % 10])
			return false;
		vis[num % 10]++;
		num /= 10;
	}
	return true;
}
int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		long long n, div;
		scanf("%lld", &n);
		for (long long i = 1; i <= MAXN; i++) {
			div = n * i;
			if (div > MAXN)
				break;
			if (check(div) && check(i)) {
				printf("%lld / %lld = %lld\n", div, i, n);
			}
		}
		if (N > 0)
			printf("\n");
	}
	return 0;
}
