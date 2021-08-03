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
	while (N--) {
		int n;
		scanf("%d", &n);
		int p;
		scanf("%d", &p);
		int arr[p];
		for (int i = 0; i < p; i++)
			cin >> arr[i];
		int sum = 0;
		for (int i = 0; i < 1 << p; i++) {
			sum = 0;
			for (int j = 0; j < p; j++) {
				if (i & (1 << j)) {
					sum += arr[j];
				}
			}
			if (sum == n)
				break;
		}
		if (sum == n)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
