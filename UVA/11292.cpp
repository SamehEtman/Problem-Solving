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
	int n, m;
	while (scanf("%d %d", &n, &m), n, m) {
		int dragons[20000];
		int knights[20000];
		for (int i = 0; i < n; i++)
			scanf("%d", &dragons[i]);
		for (int j = 0; j < m; j++)
			scanf("%d", &knights[j]);
		sort(dragons, dragons + n);
		sort(knights, knights + m);
		int d = 0, k = 0, gold = 0;
		while (d < n && k < m) {
			while (dragons[d] > knights[k] && k <m) k++;
			if (k == m) break;
			gold+=knights[k];
			d++;k++;
		}
		if (d==n) printf("%d\n" , gold);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}
