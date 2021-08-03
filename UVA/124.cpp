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

int n;
vector<vector<char>> adj;
vector<char> nodes;
bool visited[260];

bool valid(char c) {
	for (int j = 0; j < (int) adj[c].size(); j++)
		if (visited[(int) adj[c][j]])
			return 0;
	return 1;
}

void backtrack(string s) {
	if (n == (int) s.size())
		cout << s << endl;
	for (int i = 0; i < (int) nodes.size(); i++) {
		if (!visited[(int) nodes[i]]) {
			visited[(int) nodes[i]] = 1;
			if (valid(nodes[i]))
				backtrack(s + char(nodes[i]));
			visited[(int) nodes[i]] = 0;
		}
	}
}

void initial() {
	memset(visited, 0, sizeof visited);
	adj.assign(256, vector<char>());
	nodes.clear();
}
int main() {
	string s;
	int counter = 0;
	while (getline(cin, s)) {

		if (counter) {
			cout << endl;
		} else
			counter++;

		initial();

		n = 0;
		stringstream ss(s);
		char c, d;

		while (ss >> c) {
			nodes.push_back(c);
			n++;
		}

		sort(nodes.begin(), nodes.end()); // for the o/p to be lexicographically ordered
		getline(cin, s);
		ss.clear();

		ss.str(s);
		while (ss >> c >> d) {
			adj[int(c)].push_back(int(d));
		}

		backtrack("");
	}
	return 0;
}
