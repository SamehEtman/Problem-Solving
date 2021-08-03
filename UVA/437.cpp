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
struct block {
	int w, l, h;
};
bool cmp(block a , block b){
	if (a.w > b.w) return 1;
	else if (a.w == b.w && a.l > b.l) return 1;
	else if (a.w == b.w && a.l == b.l && a.h > b.h) return 1;

	return 0;
}
int main() {
	int n, counter = 1;
	while (scanf("%d", &n) && n) {

		n *= 6;
		vector<block> v(n);

		for (int i = 0; i < n; i+=6) {
			scanf("%d%d%d", &v[i].w, &v[i].l, &v[i].h);
			v[i + 1].w = v[i].w;
			v[i + 1].l = v[i].h;
			v[i + 1].h = v[i].l;

			v[i + 2].w = v[i].l;
			v[i + 2].l = v[i].w;
			v[i + 2].h = v[i].h;

			v[i + 3].w = v[i].l;
			v[i + 3].l = v[i].h;
			v[i + 3].h = v[i].w;

			v[i + 4].w = v[i].h;
			v[i + 4].l = v[i].l;
			v[i + 4].h = v[i].w;

			v[i + 5].w = v[i].h;
			v[i + 5].l = v[i].w;
			v[i + 5].h = v[i].l;

		}

		sort(v.begin() , v.end() , cmp);
		vector<int> d(n, 1), p(n, -1);

		for (int i = 0; i < n; i++) {
			d[i] = v[i].h;
			for (int j = 0; j < i; j++) {
				if (v[i].w < v[j].w && v[i].l < v[j].l && d[j] + v[i].h > d[i]) {
					d[i] = d[j] + v[i].h;
					p[i] = j;
				}
			}
		}
		int maxi = 1;
		for (int i = 0 ; i < n ; i++){
			maxi = max (maxi , d[i]);
		}

		printf("Case %d: maximum height = %d\n" , counter++ , maxi);
	}

	return 0;
}
