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
vector<int> v;
int L[MAX_N], L_id[MAX_N], P[MAX_N];
void print(int end) {
	int x = end;
	stack<int> s;
	for (; P[x] >= 0; x = P[x])
		s.push(v[x]);
	printf("-\n%d\n", v[x]);
	for (; !s.empty(); s.pop())
		printf("%d\n", s.top());
}
int main() {
	int temp;
	while (scanf("%d", &temp) == 1 ) {
		v.push_back(temp);
	}
	int lis = 0, lis_end = 0;
	for (int i = 0; i < v.size(); i++) {
		int pos = lower_bound(L, L + lis, v[i]) - L;
		L[pos] = v[i];
		L_id[pos] = i;
		P[i] = pos ? L_id[pos - 1] : -1;
		if (pos + 1 > lis || (pos + 1 == lis && lis_end < i)) {
			lis = pos + 1;
			lis_end = i;
		}
	}
	printf("%d\n", lis);
	print(lis_end);
	return 0;
}
