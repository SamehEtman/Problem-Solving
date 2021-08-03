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
	int t;
	scanf("%d", &t);
	for (int z = 1; z <= t; z++) {
		printf("Case %d: ", z);
		int n;
		scanf("%d", &n);
		int av[n];
		int needed[n];
		int sump = 0, sumq = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &av[i]);
			sump += av[i];
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &needed[i]);
			sumq += needed[i];
		}
		bool stop = 0;
		if (sump < sumq) {
			printf("Not possible\n");
			stop = 1;
		}
		if (!stop) {
			for (int i = 0; i < n; i++) {
				int tank = 0;
				bool flag = 1;
				tank += av[i] - needed[i];
				for (int j = i+1; j < n + i + 1 ; j++) {
					if (i == j)
						continue;
					if (tank < 0) {
						flag = 0;
						break;
					}
					tank += av[j%(n)] - needed[j%(n)];
				}

				if (flag) {
					printf("Possible from station %d\n", i + 1);
					break;
				}
			}

		}

	}
	return 0;
}
