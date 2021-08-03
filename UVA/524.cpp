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
int circle[20], n, T = 0;
bool used[20];
bool is_prime(int n) {
	for (int i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
void search(int m) {
	if (m == n - 1 && is_prime(circle[n - 1] + circle[n])) {
		for (int i = 0; i < n; i++)
			printf(i == n - 1 ? "%d" : "%d ", circle[i]);
		printf("\n");
	}
	for (int i = 2; i <= n; i++) {
		if (!used[i] && is_prime(circle[m] + i)) {
			circle[m + 1] = i;
			used[i] = 1;
			search(m + 1);
			used[i] = 0;
		}
	}
}
int main() {

	while (scanf("%d", &n) == 1) {
		T++;
		if (T > 1)
			printf("\n");
		circle[0] = 1;
		circle[n] = 1;
		printf("Case %d:\n", T);
		search(0);
	}
	return 0;
}
