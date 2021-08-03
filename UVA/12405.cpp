#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;
int main() {
	int t;
		scanf("%d", &t);
		int tc = 1;
		while (t--) {
			int n;
			scanf("%d", &n);
			string grid;
			cin >> grid;
			int count = 0;
			for (int i = 0 ; i < n;i++){
				if (grid[i] == '.'){
					i+=2;
					count++;
				}
			}

		printf("Case %d: %d\n",tc++, count );
	}
	return 0;
}
