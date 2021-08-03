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
int n, m;
char arr[10][10];
bool flagb = 0, flagw = 0;
int br[] = { 0, 0, 1, -1 };
int bc[] = { -1, 1, 0, 0 };
int floodfill(int x, int y, char c) {
	if (x < 0 || x >= 9 || y < 0 || y >= 9)
		return 0;
	if (c == '.' && (arr[x][y] == 'X' || arr[x][y] == 'X' + 1))
		flagb = 1;
	if (c == '.' && (arr[x][y] == 'O' || arr[x][y] == 'O' + 1))
		flagw = 1;
	if (arr[x][y] != c)
		return 0;

	arr[x][y] = c + 1;
	int ans = 1;
	for (int i = 0; i < 4; i++)
		ans += floodfill(x + br[i], y + bc[i], c);
	return ans;
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cin >> arr[i][j];
		int black = 0, white = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (arr[i][j] == '.') {
					int temp = floodfill(i, j, arr[i][j]);
					if (flagb && flagw) {
						flagb = flagw = 0;
					} else if (flagb) {
						black += temp;
						flagb = flagw = 0;
					} else if (flagw){
						white += temp;
						flagb = flagw = 0;
					}
				} else if (arr[i][j] == 'X') {

					black += floodfill(i, j, arr[i][j]);
					flagb = flagw = 0;
				} else if (arr[i][j] == 'O') {

					white += floodfill(i, j, arr[i][j]);
					flagb = flagw = 0;
				}
			}
		}
		printf("Black %d White %d\n", black, white);
	}

	return 0;
}
