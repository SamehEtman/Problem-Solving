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
	int N;
	while (scanf("%d", &N) && N != 0) {
		int arr[N + 2];
		bool flag = 1;
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		sort(arr, arr + N);
		for (int i = 1; i < N; i++) {
			if (i == N - 1) {
				if ((1422 - arr[i]) * 2 > 200) {
					flag = 0;
					break;
				}
			}
			if (arr[i] - arr[i - 1] > 200) {
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}

	return 0;
}
