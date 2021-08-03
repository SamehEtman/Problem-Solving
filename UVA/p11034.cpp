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

static const int LEFT = 0;
static const int RIGHT = 1;

int main() {
	int c;
	scanf("%d" , &c);
	while (c--) {
		int l, m;
		scanf("%d %d" , &l , &m);
		l *= 100;
		queue<int> cars[2];
		int val;
		string side;
		for (int i = 0; i < m; i++) {
			cin >> val >> side;
			if (side == "left")
				cars[LEFT].push(val);
			else
				cars[RIGHT].push(val);
		}
		int index = 0;
		int count = 0;
		while (!(cars[LEFT].empty() && cars[RIGHT].empty())) {
			int total = 0;
			while (!cars[index].empty() && total + cars[index].front() <= l) {
				total += cars[index].front();
				cars[index].pop();
			}
			index ^= 1;
			count++;
		}
		printf("%d\n" , count);
	}
	return 0;
}
