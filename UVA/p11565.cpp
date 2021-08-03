#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <limits>
#include <set>
#include <iomanip>
using namespace std;
int main() {
	int N;
	cin >> N;
	set<pair<int, pair<int, int>>> s;
	while (N--) {
		int a, b, c;
		cin >> a >> b >> c;
		bool sol = false;
		int x, y, z;
		for (x = -100; x <= 100 && !sol; x++)
			if (x * x <= c)
				for (y = -100; y <= 100 && !sol; y++)
					if (y != x && x * x + y * y <= c)
						for (z = -100; z <= 100 && !sol; z++)
							if (z != x && z != y && x + y + z == a
									&& x * y * z == b
									&& x * x + y * y + z * z == c) {
								printf("%d %d %d\n", x, y, z);
								sol = true;
							}
		if (!sol)
			cout << "No solution.\n";
	}
	return 0;
}
