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
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;

int a, b, row[8], TC, lineCounter;
bitset<30> rw, ld, rd;

void backtrack(int c) {
	if (c == 8) {
		printf("%2d      %d", ++lineCounter, row[0] + 1);
		for (int j = 1; j < 8; j++)
			printf(" %d", row[j] + 1);
		printf("\n");
	}
	if (c == b)
		backtrack(c + 1);
	else {
		for (int r = 0; r < 8; r++) {

			if (!rw[r] && !ld[r - c + 7] && !rd[r + c]) {
				rw[r] = ld[r - c + 7] = rd[r + c] = 1;
				row[c] = r;
				backtrack(c + 1);
				rw[r] = ld[r - c + 7] = rd[r + c] = 0;
			}
		}
	}
}
int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &a, &b);
		memset(row, 0, sizeof row);
		rw= ld= rd = 0;
		a--;
		b--;
		rw[a] = ld[a - b + 7] = rd[a + b] = 1;
		row[b] = a;
		lineCounter = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		if (TC)
			printf("\n");
	}
}
