// use a function to check if the number is runaround 
// push runaround numbers from 12 to 10 millions 
// output the runaround number that is equal or bigger than the given number
// don't forget that runaround can't have two or more digits of the same value
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
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;
bool check(string x, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (x[i] == x[j]) {
				return 0;
			}
		}
	}
	return 1;
}
bool isround(int n) {
	string s = to_string(n);
	if (!check(s, s.size())) {
		return 0;
	}
	bool x[s.size()] = { 0 };
	x[0] = 1;
	int i = 0;
	bool found = 0;
	while (true) {
		if (x[(i + s[i] - '0') % s.size()] == 1
				&& (i + s[i] - '0') % s.size() == 0) {
			found = 1;
			break;
		} else if (x[(i + s[i] - '0') % s.size()] == 1) {
			return 0;
			break;
		}

		x[(i + s[i] - '0') % s.size()] = 1;
		i = (i + s[i] - '0') % s.size();
	}
	if (found) {
		for (int i = 0; i < s.size(); i++) {
			if (x[i] == 0) {
				return 0;
			}
		}
	}
	return 1;
}
int main() {
	int n;
	int counter = 1;
	vector<int> v;
	for (int i = 12; i < 10000000; i++) {
		if (isround(i)){
			v.push_back(i);
		}
	}
	while (scanf("%d", &n) && n) {
		printf("Case %d: ", counter++);
		for (int i = 0; i < v.size(); i++) {
			if (v[i] >= n) {
				printf("%d\n", v[i]);
				break;
			}
		}
	}
	return 0;
}

