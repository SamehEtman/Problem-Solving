#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
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
#include <queue>
#include <set>
#include <map>
#include <iterator>
using namespace std;

int main() {
	int t;
	scanf("%d" , &t);
	//while (scanf("%d", &t) != EOF) {
		for (int z = 1; z <= t; z++) {
			int n;
			scanf("%d", &n);
			int arr[n - 1];
			int ans = 0, start = 1, ansstart = 1, end = 0;
			int sum = 0;

			for (int i = 0; i < n - 1; i++) {
				scanf("%d", &arr[i]);
				sum += arr[i];
				if (sum >= ans) {
					if (sum == ans && i+2- start <= end - ansstart) {
						continue;
					}
					ans = sum;
					end = i + 2;
					ansstart = start;

				}
				if (sum < 0) {
					sum = 0;
					start = i + 2;
				}
			}

			if (ans > 0) {
				printf(
						"The nicest part of route %d is between stops %d and %d\n",
						z, ansstart, end);
			} else
				printf("Route %d has no nice parts\n", z);
		}
	//}
	return 0;
}
