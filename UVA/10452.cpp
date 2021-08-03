#include <iostream>
#include <cstdio>
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
#include <queue>
#include <iterator>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, m, x, y;
		scanf("%d %d", &n, &m);
		char arr[n][m];
		string s = "IEHOVA#";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') {
					x = i, y = j;
				}
			}
		}
		int i = 0;
		while (i < (int)s.size()){
			if (arr[x][y-1] == s[i]){
				cout << "left";
				i++;
				y--;
			}else if (arr[x-1][y] == s[i]){
				cout << "forth";
				i++;
				x--;
			}else if (arr[x][y+1] == s[i]){
				cout << "right";
				i++;
				y++;
			}
			if (i && i != (int)s.size() ) cout <<" ";
		}
		cout << endl;
	}
	return 0;
}
