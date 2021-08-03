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
int board[8][8];
int TC, ans, sum;
bitset<30> rw, ld, rd;

void backtrack(int c) {
	if (c == 8) {
		ans = max(ans, sum);
		return;
	}
	for (int r = 0; r < 8; r++) {
		if (!rw[r] && !ld[r - c + 7] && !rd[r + c]) {
			rw[r] = ld[r - c + 7] = rd[r + c] = 1;
			sum += board[r][c];
			backtrack(c + 1);
			rw[r] = ld[r - c + 7] = rd[r + c] = 0;
			sum -= board[r][c];
		}
	}
}
int main() {
	scanf("%d", &TC);
	while (TC--) {
		rw = ld = rd = 0;
		ans = 0;
		sum = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &board[i][j]);
			}
		}
		backtrack(0);
		cout << setw(5) << ans << endl;
	}
}
