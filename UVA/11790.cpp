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
#define MAX_N 100000

int main() {
	int tc;
	scanf("%d", &tc);
	int t = 1;
	while (tc--) {
		int n;
		scanf("%d", &n);
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i].first);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i].second);
		}
		int lis[n];
		int lds[n];
		int max_i = 0, max_d = 0;
		int temp_i , temp_d;
		for (int i = 0; i < n; i++) {
			lis[i] = lds[i] =temp_i = temp_d =v[i].second;
			for (int j = 0; j < i; j++) {
				if (v[i].first > v[j].first && lis[i] < lis[j] + temp_i)
					lis[i] = lis[j] + temp_i;
				if (v[i].first < v[j].first && lds[i] < lds[j] + temp_d)
					lds[i] = lds[j] + temp_d;
			}
			max_i = max(max_i, lis[i]);
			max_d = max(max_d, lds[i]);
		}

		if (max_i >= max_d)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", t++, max_i,
					max_d);
		else
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", t++, max_d,
					max_i);

	}
	return 0;
}
