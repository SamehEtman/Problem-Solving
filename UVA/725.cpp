//just simulation
// numerator and demorator are between 1234 and 98765
// check digits uniqueness
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
	int n;
	int z = 0;
	while (scanf("%d", &n) && n) {
		if (z++)
			printf("\n");
		int abcde;
		bool flag = 1;
		for (int fghij = 1234; fghij <= 98765 / n; fghij++) {
			abcde = n * fghij;
			int used = (fghij < 10000);
			int temp = fghij;
			while (temp) {
				used |= 1 << (temp % 10);
				temp /= 10;
			}
			temp = abcde;
			while (temp) {
				used |= 1 << (temp % 10);
				temp /= 10;
			}
			if (used == (1 << 10) - 1) {
				printf("%0.5d / %0.5d = %d\n", abcde, fghij, n);
				flag = 0;
			}
		}

		if (flag)
			printf("There are no solutions for %d.\n", n);

	}
	return 0;
}
