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
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) && n) {
		bool flag = 1;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			int pos;
			scanf("%d %d", &v[i].second, &pos);
			if (i + pos < 0)
				flag = 0;
			if (i + pos >= n)
				flag = 0;
			v[i].first = i + pos;

		}
		for (int i = 0; i < n; i++) {
			if (!flag) {
				printf("-1\n");
				break;
			}
				for (int j = 0; j < n; j++) {
					if (i == j)
						continue;
					if (v[i].first == v[j].first) {
						flag = 0;
						break;
					}
				}
			}

		if (flag) {
			sort(v.begin(), v.end());
			printf("%d", v[0].second);
			for (int i = 1; i < n; i++)
				printf(" %d", v[i].second);
			printf("\n");
		}
	}
	return 0;

}
