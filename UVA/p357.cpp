#define _CRT_SECURE_nO_WARnInGS
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

int N = 5, V, coinValue[5] = { 1, 5, 10, 25, 50 };
		long long memo[6][40000];
// N and coinValue are fixed for this problem, max V is 7489
long long ways(int type, int value) {
	if (value == 0)
		return 1;
	if (value < 0 || type == N)
		return 0;
	if (memo[type][value] != -1)
		return memo[type][value];
	return memo[type][value] = ways(type + 1, value)
			+ ways(type, value - coinValue[type]);
}
int main() {
	memset(memo, -1, sizeof memo); // we only need to initialize this once
	while (scanf("%d", &V) != EOF) {
		long long x = ways(0, V);
		if (x > 1)
			printf("There are %lld ways to produce %d cents change.\n", x, V);
		else
			printf("There is only 1 way to produce %d cents change.\n", V);
	}
	return 0;
}
