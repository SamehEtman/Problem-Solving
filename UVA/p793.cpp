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
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
int main(){
	int test ;
	 scanf("%d \n" , &test);
	 while (test--){
		 char s[100];
		 int c  , pass = 0 , fail = 0;
		 scanf("%d\n" , &c);
		 UnionFind x (c+1);
		 while(gets(s) &&  strlen(s)){
			 int a , b;
			 char k;
			 sscanf(s , "%c %d %d" , &k , &a , &b);
			 if (s[0] == 'c'){
				 x.unionSet(a ,b );
			 }else if (s[0] == 'q'){
				 if (x.isSameSet(a , b)){
					 pass++;
				 }else {
					 fail++;
				 }
			 }
		 }
		 printf("%d,%d\n" , pass , fail);
		 if (test>0) printf("\n");
	 }
	return 0;

}
