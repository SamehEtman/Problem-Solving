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
bool cmp(pair<int, int> a, pair<int, int> b) {
	return ( a.second >  b.second);
}
int main() {
	int n;
	int counter = 1;
	while (cin >> n && n != 0) {
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &v[i].first, &v[i].second);
		}
		sort(v.begin(), v.end(), cmp);
		int ans = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += v[i].first;
			ans = max(ans, sum + v[i].second);
		}
		printf("Case %d: %d\n", counter++, ans);
	}
	return 0;
}
