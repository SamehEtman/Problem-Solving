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
int n, m;
string rule, dis[110], digits[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8",
		"9" };
void generate(int v, string ans) {
	if (v == rule.size()) {
		cout << ans << endl;
		return;
	}
	switch (rule[v]) {
	case '#':
		for (int i = 0; i < n; i++)
			generate(v + 1, ans + dis[i]);
		break;
	case '0':
		for (int i = 0; i < 10; i++)
			generate(v + 1, ans + digits[i]);
		break;
	}
}
int main() {
	while (scanf("%d", &n)==1) {
		printf("--\n");
		for (int i = 0; i < n; i++)
			cin >> dis[i];
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			cin >> rule;
			generate(0, "");
		}
	}
}
