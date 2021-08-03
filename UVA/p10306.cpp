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

int memo[500][500] , m ,s ;
vector<pair<int , int>> v (50);

int change ( int st , int nd){
	if (sqrt(st*st + nd*nd) == s) return 0;
	if (sqrt(st*st + nd*nd) > s ) return 3000000;
	if (memo[st][nd] != -1) return memo[st][nd];
	int best = 200000;
	for (int i = 0 ; i < m ; i++){
		best = min (best , 1 + change( st + v[i].first , nd + v[i].second));
	}
	return memo[st][nd] = best;
}
int main() {
	int n;
	scanf("%d" , &n);
	while (n--) {
		memset(memo, -1, sizeof memo);
		scanf("%d%d" , &m , &s);
		for (int i = 0 ;i < m ; i++){
			cin >> v[i] .first >> v[i].second;
		}

		int x = change( 0 , 0);
		if (x >= 200000) printf("not possible\n");
		else cout << x <<endl;

	}
	return 0;
}
