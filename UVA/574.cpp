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
int t, n;
int arr[120];
map<vector<int>, bool> solution;
vector<int> sol;
void search(int k, int m, int sum, vector<int> v) {
	if (sum == t) {
		if (solution[v] == true)
			return;
		solution[v] = true;
		for (int i = 0; i < k; i++)
			printf(i == k - 1 ? "%d" : "%d+", v[i]);
		printf("\n");
		return;

	}
	if (sum > t || m == n)
		return;
	for (int i = m; i < n; i++) {
		v.push_back(arr[i]);
		search(k + 1, i + 1, sum + arr[i], v);
		v.pop_back();
	}
}
int main() {
	while (scanf("%d %d", &t, &n) == 2 && t != 0 && n != 0) {
		solution.clear();
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		printf("Sums of %d:\n", t);
		search(0, 0, 0, sol);
		if (solution.size() == 0)
			printf("NONE\n");
	}

	return 0;
}
