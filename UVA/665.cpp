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
using namespace std;

int main() {
	int m, ma;
	scanf("%d", &m);
	ma = m;
	while (m--) {
		if (m != ma-1)
			cout << endl;
		int n, k;
		scanf("%d %d", &n, &k);
		bool fc[n + 1];
		memset(fc, 1, n + 1);
		while (k--) {
			int p;
			scanf("%d", &p);
			int coins[p * 2];
			for (int i = 0; i < p * 2; i++)
				scanf("%d", &coins[i]);
			char sign;
			cin >> sign;
			if (sign == '=') {
				for (int i = 0; i < p * 2; i++) {
					fc[coins[i]] = 0;
				}
			} else if (sign == '<') {
				for (int i = 1; i < n + 1; i++) {
					bool exists = 0;
					for (int j = 0; j < 2 * p; j++) {
						if (i == coins[j]) {
							exists = 1;
						}
					}
					if (!exists)
						fc[i] = 0;
				}
			} else if (sign == '>') {
				for (int i = 1; i < n + 1; i++) {
					bool exists = 0;
					for (int j = 0; j < 2 * p; j++) {
						if (i == coins[j]) {
							exists = 1;
						}
					}
					if (!exists)
						fc[i] = 0;
				}
			}
		}
		int index = 0, num = 0;
		for (int i = 1; i < n + 1; i++) {
			if (fc[i] == 1) {
				index = i;
				num++;
			}
		}
		if (num == 1)
			cout << index << endl;
		else
			cout << 0 << endl;

	}
	return 0;

}
