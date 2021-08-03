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

int coins[21];
long long dp[22][10002] = { 0 };

long long solve(int i, int val) {
	if (val == 0)
		return 1;
	if (val < 0 || i > 20)
		return 0;
	if (dp[i][val] != -1)
		return dp[i][val];
	return dp[i][val] = solve(i + 1, val) + solve(i, val - coins[i]);
}

int main() {
	int n;
	memset(dp , -1 , sizeof dp);
	for (int i = 1; i <= 21; i++)
		coins[i - 1] = i * i * i;

	while (scanf("%d", &n) == 1) {
		printf("%lld\n", solve(0 , n));
	}

	return 0;
}
/**
 * bottom-up
 */
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

int coins[21];
long long dp[22][10002] = { 0 };


int main() {
	int n;
	for (int i = 1; i <= 21; i++)
		coins[i - 1] = i * i * i;
	for (int i = 0 ; i <= 21;i++){
		dp[i][0] = 1;
	}
	while (scanf("%d", &n) == 1) {
		for (int i = 1 ;i <= 21 ; i++){
			for (int j = 1 ; j <=n ; j++){
				if (coins[i-1] <= j) dp[i][j] = dp[i-1][j] + dp[i] [j-coins[i-1]];
				else dp[i][j] = dp[i-1][j];
			}
		}
		printf("%lld\n" , dp[21][n]);
	}

	return 0;
}
 *
 * /
