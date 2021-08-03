#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
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
#include <string>
#include <queue>
#include <iterator>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
	int n, m;
	vector<vector<int>> v;
	while (scanf("%d %d", &n, &m) != EOF) {
		v.assign(1000000, vector<int>());
		for (int i = 0; i < n; i++) {
			int d;
			scanf("%d", &d);
			v[d].push_back(i + 1);
		}
		int a, b;
		while (m--) {
			scanf("%d %d", &a, &b);
			if (a - 1 < v[b].size()) {
				cout << v[b][a - 1] << endl;
			} else
				cout << 0 << endl;
		}
	}
	return 0;
}
