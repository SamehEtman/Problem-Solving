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
int m, n;
char arr[120][120];
void floodfill(int x , int y){
	if (x >= m || x <0 || y >=n || y <0) return;
	if (arr[x][y] != '@') return;
	arr[x][y] = '.';
	for (int i = -1 ; i<=1 ; i++)
		for (int j = -1 ; j <=1 ; j++)
			floodfill(x+i , y+j);
}
int main() {
	while (scanf("%d %d", &m, &n)) {
		if (m == 0)
			break;
		for (int i = 0 ; i <  m; i++)
			for (int j = 0 ;j < n; j++)
				cin >> arr[i][j];
		int ans = 0;
		for (int i = 0 ; i < m ; i++){
			for (int j = 0 ; j < n ; j++){
				if (arr[i][j] == '@'){
					floodfill(i,j);
					ans++;
				}
			}
		}
		printf("%d\n" , ans);
	}
	return 0;
}
