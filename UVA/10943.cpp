#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	long long dp[201][201] = { 0 };
	int n, k;
	for (int i = 0; i <= 200; i++)
		dp[i][0] = 1;
	for (int i = 0; i <= 200; i++)
		dp[0][i] = 1;

	for (ll i = 1; i <= 200; i++) {
		for (ll j = 1; j <= 200; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000;
		}
	}
	while (scanf("%d %d", &n, &k) == 2) {
		if (n == 0 && k == 0)
			break;
		printf("%lld\n", dp[k - 1][n]);
	}
	return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	long long dp[201][201] = { 0 };
	int N, K;
	while (scanf("%d %d", &N, &K) == 2) {
		if (N == 0 && K == 0)
			break;
		for (int i = 0; i <= K; i++)
			dp[i][0] = 1;
		for (int i = 0; i <= N; i++)
			dp[0][i] = 1;

		for (ll i = 1; i <= K; i++) {
			for (ll j = 1; j <= N; j++) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000;
			}
		}

		printf("%lld\n", dp[K - 1][N]);
	}
	return 0;
}
 * */