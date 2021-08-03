/*
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
vector<int> v;
int memo[200][200];
int dp(int id, int rem) {
	if (id == (int) v.size() || rem == 0)
		return 0;
	if (memo[id][rem] != -1)
		return memo[id][rem];
	if (v[id] > rem)
		return memo[id][rem] = dp(id + 1, rem);
	return memo[id][rem] = max(dp(id + 1, rem), v[id] + dp(id + 1, rem - v[id]));
}
int main() {
	int tc;
	scanf("%d", &tc);
	cin.ignore();
	while (tc--) {
		memset(memo, -1, sizeof memo);
		string s;
		getline(cin, s);
		stringstream ss(s);
		int tmp, sum = 0;
		v.clear();
		while (ss >> tmp) {
			v.push_back(tmp);
			sum += tmp;
		}
		if (sum & 1)
			printf("NO\n");
		else {
			if (dp(0, sum / 2) == sum / 2)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}

 * */

/*
 *
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

int DP[202][202];
int main() {

	int tc;
	scanf("%d", &tc);
	cin.ignore();
	while (tc--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		int tmp, sum = 0;
		vector<int> v(1, 0);
		while (ss >> tmp) {
			v.push_back(tmp);
			sum += tmp;
		}

		int N = v.size() - 1;
		if (sum & 1) // is sum is odd no need to compute it cannot be divided by 2
			printf("NO\n");
		else {
			int MW = sum / 2;  		// max weight

			for (int i = 0; i <= N; i++)	// initialization of the table
				DP[i][0] = 0;
			for (int j = 0; j <= MW; j++)
				DP[0][j] = 0;			// if maximum capacity is 0 we cannot put any bags

			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= MW; j++) {
					if (v[i] > j)
						DP[i][j] = DP[i - 1][j];
					else
						DP[i][j] = max(DP[i - 1][j],
								v[i] + DP[i - 1][j - v[i]]);
				}
			}

			if (DP[N][MW] == sum / 2)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;

}
 * */
