#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <iterator>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

#define N 2048
#define P 309
#define K 16

long long dp[P][N][K], prime[P];
void constructPrime() {
	int nPrime = 0, isPrime[N];
	memset(isPrime, true, sizeof isPrime);
	for (int i = 2; i < N; ++i)
		if (isPrime[i] && (prime[nPrime++] = i))
			for (int j = i * i; j < N; j += i)
				isPrime[j] = false;
}

long long solve(int i, int n, int k) {
	if (n == 0 && k == 0)
		return dp[i][n][k] = 1;
	if (k < 0 || n < 0 || prime[i] > n  || i == P)
		return dp[i][n][k] = 0;

	if (dp[i][n][k] != -1)
		return dp[i][n][k];

	return dp[i][n][k] = solve(i + 1, n - prime[i], k - 1)
			+ solve(i + 1, n, k);
}

int main() {
	int n, k;
	constructPrime();
	memset(dp, -1, sizeof dp);
	while (scanf("%d %d", &n, &k)) {
		if (n == 0 && k == 0) {
			break;
		}
		printf("%lld\n", solve(0, n, k));
	}
	return 0;

}
