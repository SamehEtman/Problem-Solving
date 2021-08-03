/*
 * bottom-up
 * 
 * #include <iostream>
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

int coins[] = { 1 , 5 , 10 , 25 , 50};
int dp[6][8000] = { 0 };

int main() {
	for (int i = 0; i < 6; i++)
		dp[i][0] = 1;
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= n; j++) {
					if (j-coins[i-1] >=0)dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i-1]];
					else dp[i][j] = dp[i - 1][j];
			}
		}
		cout << dp[5][n] << endl;
	}

	return 0;
}
 * 
 * 
 * top-down 
 * 
 * #include <iostream>
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

int coins[] = { 1, 5, 10, 25, 50 };
int dp[6][8000];

int solve(int i, int val) {
	if (val == 0)
		return 1;
	if (val < 0 || i > 4)
		return 0;
	if (dp[i][val] != -1)
		return dp[i][val];

	return dp[i][val] = solve(i + 1, val) + solve(i, val - coins[i]);
}

int main() {
	memset(dp, -1, sizeof dp);
	int n;
	while (scanf("%d", &n) == 1) {
		printf("%d\n", solve(0, n));
	}

	return 0;
}
 * 
 * */