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
	int n;
	while (cin >> n && n != 0) {
		map<pair<int, int>, int> mp;
		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			mp[make_pair(a, b)]++;
		}
		bool flag = true;
		for (map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end();
				it++) {
			pair<int, int> temp = it->first;
			int t = temp.first;
			temp.first = temp.second;
			temp.second = t;
			if (mp[it->first] != mp[temp]) {
				flag = false;
				break;
			}
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
	return 0;
}
