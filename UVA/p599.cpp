/*My Solution*/
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
	vi p, rank, setSize;                       // remember: vi is vector <int>
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
		p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			// rank is used to keep the tree short
			if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
			else                   {
				p[x] = y; setSize[y] += setSize[x];
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
	int n;
	scanf("%d", &n);
	while (n--){
		UnionFind x(30);
		//int a, b;
		char s[100];
		while (gets(s)){
			if (s[0] == '*') break;
			if (!x.isSameSet(s[1] - 64, s[3] - 64)){
				x.unionSet(s[1] - 64, s[3] - 64);
			}
		}
		int trees = 0, acorns = 0;
		gets(s);
		int len = strlen(s);
		set <int> l;
		for (int i = 0; i < len; i += 2){
			//cout << x.numDisjointSets() << endl;
			if (s[i] - 64 == x.findSet(s[i] - 64) && x.sizeOfSet(s[i] - 64) == 1) acorns++;
			else
			l.insert(x.findSet(s[i] - 64));
		}
		printf("There are %d tree(s) and %d acorn(s).\n", l.size(), acorns);
	}

	return 0;
}
/*****************************************************************************************************/
/*Some Solution */
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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define maxN 30
using namespace std;

int Lab[maxN];

int GetRoot(int v) {
    if (Lab[v] < 0) return v;
    Lab[v] = GetRoot(Lab[v]);
    return Lab[v];
}

void Union(int r1, int r2) {
    int x = Lab[r1] + Lab[r2];
    if (Lab[r1] > Lab[r2]) {
        Lab[r1] = r2;
        Lab[r2] = x;
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }
}

int main(){
	int Case, u, v;
	    char s[100];
	    scanf("%d", &Case); scanf(" ");
	    while (Case--) {
	        FOR (i, 1, 26) Lab[i] = -1;
	        while (gets(s)) {
	            if (s[0]=='*') break;
	            u = s[1]-64; v = s[3] - 64;
	            u = GetRoot(u); v = GetRoot(v);
	            if (u!=v) Union(u, v);
	        }
	        gets(s); int len = strlen(s);
	        int tree = 0, corn = 0;
	        for (int i=0; i<len; i+=2) {
	            int u = s[i] - 64;
	            if (Lab[u]==-1) corn++;
	            else if (Lab[u]<0) tree++;
	        }
	        printf("There are %d tree(s) and %d acorn(s).\n", tree, corn);
	}
	return 0;
}
