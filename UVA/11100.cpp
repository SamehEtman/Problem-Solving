#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;
int main() {
	int n;
	bool first = 0;
	while (scanf("%d", &n) && n != 0) {
		if (n && first)
			cout << endl;
		first = 1;
		int arr[n + 1];
		arr[n] = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		int rep = 1, maxrep = 1;
		for (int i = 0; i < n; i++) {
			if (arr[i] == arr[i + 1]) {
				rep++;
				continue;
			}
			maxrep = max(rep, maxrep);
			rep = 1;
		}
		cout << maxrep << endl;
		for (int i = 0; i < maxrep; i++) {
			for (int j = i; j < n; j += maxrep) {
				if (i != j) {
					cout << " ";
				}
				cout << arr[j];
			}
			cout << endl;
		}
	}
	return 0;
}
