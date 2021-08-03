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
bool cmp(pair<int, pair<int, int>> a  , pair<int, pair<int, int>> b){
	if (a.first == b.first) return a.second.first < b.second.first;
	return a.first > b.first;
}
int main() {
	int w, iq, i = 1;
	vector<pair<int, pair<int, int>>> v;
	while (scanf("%d%d", &w, &iq) == 2)
		v.push_back(make_pair(iq, make_pair(w, i++)));

	int n = v.size();
	sort(v.begin(), v.end() , cmp);
	vector<int> d(n, 1), p(n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second.first > v[j].second.first && v[i].first < v[j].first &&d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
				p[i] = j;
			}
		}
	}
	int pos = 0, maxi = 1;
	for (int i = 0; i < n; i++) {
		if (d[i] > maxi) {
			maxi = d[i];
			pos = i;
		}
	}
	vector<pair<int, pair<int, int>>> ans;
	while (pos != -1) {
		ans.push_back(make_pair(v[pos].second.first , make_pair(v[pos].first , v[pos].second.second)));
		pos = p[pos];
	}
	sort(ans.begin() , ans.end());
	printf("%d\n" , (int) ans.size());
	for (int i = 0 ;i <(int) ans.size() ; i++){
		printf("%d\n" , ans[i].second.second);
	}
	return 0;
}
