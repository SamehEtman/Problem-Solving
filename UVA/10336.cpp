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
char arr[500][500];
int val['z' + 1];
int br[] = { 0, 0, 1, -1 };
int bc[] = { 1, -1, 0, 0 };
void floodfill(int x, int y, char c) {
	if (x >= n || x < 0 || y >= m || y < 0)
		return;
	if (arr[x][y] != c)
		return;
	arr[x][y] = '.';
	for (int i = 0; i < 4; i++)
		floodfill(x + br[i], y + bc[i], c);
}
bool cmp(pair<int,int> a , pair <int,int> b){
	if (a.first > b.first) return a.first > b.first;
	else if (a.first == b.first) return a.second < b.second;
	else  return 0;
}
int main() {
	int tc, counter = 1;
	scanf("%d", &tc);
	while (tc--) {
		memset(val, 0, sizeof val);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != '.') {
					val[(int) arr[i][j]]++;
					floodfill(i, j, arr[i][j]);
				}
			}
		}
		vector<pair<int, char>> v;
		for (int i = 'a'; i <= 'z'; i++) {
			if (val[i]) {
				v.push_back(make_pair(val[i], i));
			}
		}
		sort(v.begin(), v.end() , cmp);
		printf("World #%d\n", counter++);
		for (int i = 0; i < (int) v.size(); i++) {
			printf("%c: %d\n", v[i].second, v[i].first);
		}
	}

	return 0;
}
