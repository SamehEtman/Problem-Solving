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

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		sort(v.rbegin(), v.rend());

		int ans = 0;
		for (int i = 2; i < n; i += 3) {
			ans += v[i];
		}
		cout << ans << endl;
	}
	return 0;
}
