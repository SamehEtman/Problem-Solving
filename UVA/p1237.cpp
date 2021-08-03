#define _CRT_SECURE_NO_WARNINGS
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
int n;
#define ull unsigned long long
ull eval(int coff[30], int i) {
	ull a = 0;
	ull currentn = 1;
	for (int j = 0; j <= n; j++) {
		a += coff[j] * currentn;
		currentn *= i;
	}
	return a;
}
int main() {
	int t;
	scanf("%d", &t);
	int z = 1;
	while (t--) {
		if (z == 0) cout <<endl;
		int d;
		scanf("%d", &d);
		vector<pair<string, pair<int, int>>> c;
		for (int i = 0; i < d; i++) {
			string x;
			int y, z;
			cin >> x;
			scanf("%d %d", &y, &z);
			c.push_back(make_pair(x, make_pair(y, z)));
		}
		int qn;
		scanf("%d" , &qn);
		for (int i = 0; i < qn; i++) {
			int q;
			scanf("%d" , &q);
			int count = 0;
			int temp = -1;
			for (int j = 0; j < c.size(); j++) {
				if (q >= c[j].second.first && q <= c[j].second.second) {
					count++;
					temp = j;
				}
				if (count > 1) {
					cout << "UNDETERMINED\n";
					break;
				}
			}
			if (count == 1) {
					cout << c[temp].first << endl;
			} else if(count == 0) {
				cout << "UNDETERMINED\n";
			}
		}
		z = 0;
	}
	return 0;
}
