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
using namespace std;

int main() {
	int S, B;
	int left[100005], right[100005];
	while (scanf("%d %d", &S, &B) && B != 0 && S != 0) {
		for (int i = 1; i <= S; i++) {
			left[i] = i - 1;
			right[i] = i + 1;
		}
		int l, r;
		for (int i = 0; i < B; i++) {
			scanf("%d %d", &l, &r);
			left[right[r]] = left[l];
			if (left[l] != 0)
				printf("%d ", left[l]);
			else
				printf("* ");
			right[left[l]] = right[r];
			if (right[r] != S+1)
				printf("%d\n", right[r]);
			else
				printf("*\n");
		}
		printf("-\n");
	}
	return 0;
}
