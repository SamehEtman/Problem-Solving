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
vector<pair<int, int>> v(20);
vector<pair<int, int>> sol(20);
bool used[20];
bool valid(pair<int, int> st, pair<int, int> nd) {
	if (st.second == nd.first)
		return 1;
	return 0;
}
bool solve(int c) {
	if (c == n && valid(sol[c] , v[m+1])){
		return 1;
	}
	for (int i = 1; i < m+1; i++) {
		if (!used[i]&&valid(sol[c], v[i])) {
			sol[c + 1] = v[i];
			used[i] = 1;
			if(solve(c + 1)) return 1;
			used[i] = 0;
		} else {
			swap(v[i].first, v[i].second);
			if (!used[i]&&valid(sol[c], v[i])) {
				sol[c + 1] = v[i];
				used[i] = 1;
				if (solve(c + 1)) return 1;
				swap(v[i].first, v[i].second);
				used[i] = 0;
			}else
				swap(v[i].first, v[i].second);
		}
	}
	return 0;
}
int main() {
	while (scanf("%d" , &n) , n) {
		v.clear();
		sol.clear();
		for (int i = 0 ; i < 20;i++ ) used[i] = 0;
		scanf("%d", &m);
		scanf("%d %d", &v[0].first, &v[0].second);
		sol[0] = v[0];
		scanf("%d %d", &v[m + 1].first, &v[m + 1].second);
		for (int i = 1; i < m +1; i++)
			scanf("%d %d", &v[i].first, &v[i].second);
		if (solve(0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
