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
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		double out = 0.0;
		int K;
		scanf("%d", &K);
		vector<pair<char, int>> v(K);
		for (int i = 0; i < K; i++) {
			cin >> v[i].first >> v[i].second;
		}
		int M;
		scanf("%d", &M);
		M++;
		while (M--) {
			string s;
			getline(cin, s);
			for (int i = 0; i < s.size(); i++) {
				for (int j = 0; j < K; j++) {
					if (s[i] == v[j].first) {
						out += v[j].second;
					}
				}
			}
		}
		printf("%.2f$\n", out / 100);
	}
	return 0;
}
