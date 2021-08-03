//#include "std_lib_facilities.h"
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
int dp[20100] = { 0 };
int coins[102];
int n;
int main()
try {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		int sum;
		cin >> sum >> n;
		for (int i = 1; i < 20100; i++)
			dp[i] = 1e8;
		for (int i = 1; i <= n; i++)
			cin >> coins[i];
		for (int i = 1; i <= n; i++) {
			for (int j = sum; j >= 0; j--) {
				if (dp[j] < 1e8) {
					dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1);
				}
			}

		}

		for (int i = sum;; i++) {
			if (dp[i] != 1e8) {
				printf("%d %d\n", i, dp[i]);
				break;
			}
		}

	}

}
catch (exception &e) {
	cerr << "error: " << e.what() << '\n';
//keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
//keep_window_open();
	return 2;
}
