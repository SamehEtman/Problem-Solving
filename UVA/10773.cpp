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

int main() {
	int tc, counter = 1;
	scanf("%d", &tc);
	while (tc--) {
		long double d, v, u;
		cin >> d >> v >> u;
		if (v > u || u == 0 || u == v || v == 0) {
			printf("Case %d: can't determine\n", counter++);
			continue;
		}
		long double v2 = d / sqrt(pow(u, 2) - pow(v, 2));
		printf("Case %d: ",counter++);
		cout << fixed << setprecision(3) <<v2 - (d / u) << endl;
	}

}
