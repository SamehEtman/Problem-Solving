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
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n) {
		if (n == 0)
			break;
		cin >> m;
		char a[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		int total = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int x = i; x < n; x++)
					for (int y = j; y < m; y++){
						bool good = true;
						for (int h = i; h <= x && good; h++)
							for (int w = j; w <= y && good; w++)
								if (a[h][w] != '1')
									good = false;
						if (good)
							total++;
					}
		cout << total << "\n";
	}

	return 0;
}
