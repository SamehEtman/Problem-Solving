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
	int n, r, counter = 1;
	while (scanf("%d %d", &n, &r) != EOF) {
		if (n == 0 && r == 0) break;
		if (n / r > 26) {
			printf("Case %d: impossible\n", counter++);
		} else {
			printf("Case %d: %d\n", counter++, (n-1) / r);
		}
	}

}
