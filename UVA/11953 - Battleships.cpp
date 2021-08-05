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
#include <iterator>
using namespace std;
char arr[120][120];
int n;
int br[4] = { 0, 0, -1, 1 };
int bc[4] = { 1, -1, 0, 0 };
int floodfill(int x, int y) {
	if (x >= n || x < 0 || y >= n || y < 0)
		return 0;
	if (arr[x][y] == '.')
		return 0;
	arr[x][y] = '.';
	int ans = 1;
	for (int i = 0; i < 4; i++) {
		ans += floodfill(x + br[i], y + bc[i]);
	}
	return ans;
}
int main() {
	int tc , counter = 1;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		int ans = 0;
		for (int i = 0 ; i < n ; i++){
			for (int j = 0 ; j < n ; j++) {
				if (arr[i][j] == 'x'){
					floodfill(i,j);
					ans ++;
				}
			}
		}
		printf ("Case %d: %d\n" , counter ++ , ans);

	}
	return 0;
}
