#define _CRT_SECURE_nO_WARnInGS
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
int arr[350][350];
int main() {
	int tc;
	scanf("%d", &tc);
	int t = 1;
	while (tc--) {
		int n, m, p;
		scanf("%d %d %d", &n, &m, &p);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &arr[i][j]);
				if (i > 0)
					arr[i][j] += arr[i - 1][j];
				if (j > 0)
					arr[i][j] += arr[i][j - 1];
				if (i > 0 && j > 0)
					arr[i][j] -= arr[i - 1][j - 1];
			}
		}
		pair<long long, long long> ans = make_pair(p, 0);
		bool flag = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int k = i; k < n; k++)
					for (int l = j; l < m; l++) {
						long long temp = arr[k][l];
						if (i > 0)
							temp -= arr[i - 1][l];
						if (j > 0)
							temp -= arr[k][j - 1];
						if (i > 0 && j > 0)
							temp += arr[i - 1][j - 1];

						if (temp <= p) {
							flag = 1;
							if (ans.second < (abs(i - k)+1) * (abs(j - l)+1)) {
								ans.first = temp;
								ans.second = (abs(i - k)+1) * (abs(j - l)+1);

							} else if (ans.second ==(abs(i - k)+1) * (abs(j - l)+1)) {
								if (temp < ans.first) {
									ans.first = temp;
									ans.second =(abs(i - k)+1) * (abs(j - l)+1);
								}
							}

						}
					}
		if (flag)
			printf("Case #%d: %lld %lld\n",t++, ans.second , ans.first);
		else
			printf("Case #%d: %lld %lld\n",t++, ans.second , 0);
	}
	return 0;
}
