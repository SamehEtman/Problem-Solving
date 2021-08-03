// make an array that represents the heights 
// when the height changes u add the change to the output
#include <iostream>
#include <vector>
#include <string>
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
	int l, h, r;
	int arr[10002] = { 0 };
	int maxr = 1;
	int minl = 100002;
	while (scanf("%d %d %d\n", &l, &h, &r) != EOF) {
		minl = min(minl, l);
		maxr = max(maxr, r);
		for (int i = l; i < r; i++) {
			arr[i] = max(arr[i], h);
		}
	}
	for (int i = minl; i <= maxr + 1; i++) {
		if (arr[i] != arr[i - 1]) {
			if (i == minl)
				printf("%d %d", i, arr[i]);
			else
				printf(" %d %d", i, arr[i]);

		}
	}
	printf("\n");
	return 0;
}
