#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
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
#include <string>
#include <queue>
#include <iterator>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<int> visited;
vector<vii> adjlist;
int dfs(int u) {
	visited[u] = 1;
	for (int i = 0; i < adjlist[u].size(); i++) {
		if (!visited[adjlist[u][i].first]) {
			dfs(adjlist[u][i].first);
		}
	}
}
int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	vii v;
	int a, b;
	char c;
	while (scanf("%d %d %c", &a, &b, &c) != EOF) {

		int direction;
		if (c == 'N')
			direction = 0;
		else if (c == 'E')
			direction = 1;
		else if (c == 'S')
			direction = 2;
		else if (c == 'W')
			direction = 3;
		string s;
		bool flag = 1;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			//cout << a << " " << b << " " << c << endl;
			if (s[i] == 'R') {
				direction = (direction + 1) % 4;
			} else if (s[i] == 'L') {
				if (direction == 0)
					direction = 3;
				else
					direction = (direction - 1) % 4;
			} else if (s[i] == 'F') {
				if (direction == 0) {
					if (b + 1 > y) {
						if (find(v.begin(), v.end(), pair<int, int>(a, b))
								== v.end()) {
							flag = false;
							v.push_back(make_pair(a, b));
							break;
						}

					} else
						b++;
				} else if (direction == 1) {
					if (a + 1 > x) {
						if (find(v.begin(), v.end(), pair<int, int>(a, b))
								== v.end()) {
							flag = false;
							v.push_back(make_pair(a, b));
							break;
						}

					} else
						a++;
				} else if (direction == 2) {
					if (b - 1 < 0) {
						if (find(v.begin(), v.end(), pair<int, int>(a, b))
								== v.end()) {
							flag = false;
							v.push_back(make_pair(a, b));
							break;
						}
					} else
						b--;
				} else if (direction == 3) {
					if (a - 1 < 0) {
						if (find(v.begin(), v.end(), pair<int, int>(a, b))
								== v.end()) {
							flag = false;
							v.push_back(make_pair(a, b));
							break;
						}
					} else
						a--;
				}

			}
			if (direction == 0)
						c = 'N';
					else if (direction == 1)
						c = 'E';
					else if (direction == 2)
						c = 'S';
					else if (direction == 3)
						c = 'W';
		}
		if (direction == 0)
			c = 'N';
		else if (direction == 1)
			c = 'E';
		else if (direction == 2)
			c = 'S';
		else if (direction == 3)
			c = 'W';
		if (!flag) {
			cout << v[v.size() - 1].first << " " << v[v.size() - 1].second <<" " << c
					<< " LOST\n";
		} else {
			cout << a << " " << b << " " << c << endl;
		}
	}

	return 0;
}
