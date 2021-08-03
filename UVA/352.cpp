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
vector<vector<int>> adj;
bool visited[100];
int dr[8] = { -1, 0, 1, -1, 1, 1, -1, 0 };
int dc[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
char arr[30][30];
int n;
int floodfill(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n)
		return 0;
	if (arr[x][y] != '1')
		return 0;
	arr[x][y]='.';
	int sum = 1;
	for (int i = 0; i < 8; i++) {
		sum += floodfill(x + dr[i], y + dc[i]);
	}
	return sum;
}
int main() {
	int counter = 1;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		int ans = 0;
		for (int i = 0 ; i < n ; i++){
			for (int j = 0 ; j < n ; j++){
				if (arr[i][j] == '1'){
					floodfill(i,j);
					ans ++;
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n" , counter++ , ans);
	}
	return 0;
}
