#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <math.h>
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
#define ull unsigned long long
#define EPS 1e-9
int n, m;
int arr[1000000];
bool is_valid(int max) {
	for (int i = 0; i < n; i++) {
		if (arr[i + 1] - arr[i] > max)
			return 0;
		if (arr[i + 1] - arr[i] == max)
			max--;
	}
	return 1;
}
int main() {
	int c;
	scanf("%d", &c);
	int count = 1;
	while (c--) {
		scanf("%d", &n);
		int hi = 10;
		arr[0] = 0;
		for (int i = 1; i < n + 1; i++) {
			scanf("%d", &arr[i]);
			hi += arr[i];
		}
		int lo = 1;
		int best;
		while (hi - lo > 0) {

			int mid = (hi + lo) / 2;

			if (is_valid(mid)) {
				hi = mid ;
				//best = mid;
			} else {
				lo = mid + 1;
			}
			//cout << lo << " " << mid << " " << hi <<endl;
		}
		printf("Case %d: %d\n" , count , lo);
		count++;
	}

	return 0;
}
