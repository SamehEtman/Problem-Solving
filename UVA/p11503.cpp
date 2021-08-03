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
using namespace std;

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
	vi p, rank, setSize;                       // remember: vi is vector<int>
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1);
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];
			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
	int numDisjointSets() {
		return numSets;
	}
	int sizeOfSet(int i) {
		return setSize[findSet(i)];
	}
};
map<string, int> m;
int value[100000];
int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		UnionFind x(100000);
		for (int i = 0; i < 100000; i++) {
			value[i] = 1;
		}
		m.clear();
		int n;
		scanf("%d", &n);
		while (n--) {
			string name1, name2;
			int p1, p2;
			cin >> name1 >> name2;
			map<string, int>::iterator it;
			it = m.find(name1);
			if (it != m.end()) {
				p1 = it->second;
			} else {
				p1 = m.size();
				m.insert(make_pair(name1, p1));
			}
			it = m.find(name1);
			if (it != m.end()) {
				p1 = it->second;
			} else {
				p1 = m.size();
				m.insert(make_pair(name1, p1));
			}
			it = m.find(name2);
			if (it != m.end()) {
				p2 = it->second;
			} else {
				p2 = m.size();
				m.insert(make_pair(name2, p2));
			}
			if (!x.isSameSet(p1, p2)) {
				int set1 = x.findSet(p1);
				int set2 = x.findSet(p2);
				x.unionSet(p1, p2);
				int set3 = x.findSet(p1);
				value[set3] = value[set2] + value[set1];
			}
			int set = x.findSet(p1);
			cout << value[set] << endl;
		}
	}
	return 0;

}
