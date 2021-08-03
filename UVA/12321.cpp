#include <iostream>
#include <vector>
#include <string>
#include <map>
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
	int l, g;
	while (cin >> l >> g && !(l == 0 && g == 0)) {
		vector<pair<int, int>> v;
		for (int i = 0; i < g; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a - b, a + b));
		}
		sort(v.begin() , v.end());
		vector<pair<int, int>> seg;
		int currentl = 0, i = 0, nextl = 1;
		bool flag = 1;
		while (l > currentl) {
			int last = -1;
			for (; i < g; i++) {
				if (v[i].first > currentl) {
					break;
				} else if (v[i].second > nextl) {
					nextl = v[i].second;
					last = i;

				}
			}
			if (last == -1) {
				flag = 0;
				break;
			}
			currentl = nextl;
			seg.push_back(make_pair(v[last].first , v[last].second));
		}
		if (!flag) {
			cout << -1 <<endl;
		}else {
			cout << v.size() - seg.size() << endl;
		}
	}
	return 0;
}
