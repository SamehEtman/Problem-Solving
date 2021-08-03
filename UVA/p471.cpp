// bound the numerator to 9876543210
// numerator = Denominator * the number given
// check if digits are unique
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

bool check(long long n) {
	int vis[10] = { 0 };
	while (n) {
		if (vis[n % 10])
			return false;
		vis[n % 10]++;
		n /= 10;
	}
	return true;
}
int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		long long n, numerator;
		scanf("%lld", &n);
		for (long long i = 1; i <= MAXN; i++) {
			numerator = n * i;
			if (numerator > MAXN)
				break;
			if (check(numerator) && check(i)) {
				printf("%lld / %lld = %lld\n", numerator, i, n);
			}
		}
		if (N > 0)
			printf("\n");
	}
	return 0;
}
