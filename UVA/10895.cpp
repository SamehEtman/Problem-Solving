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
int main(){
	int m, n, r, value;
	int cols[1002];
	vector< vector< pair<int, int> > > matrix;
	while (cin >> m >>n ) {
		matrix.clear();
		for (int i = 0; i < n; i++) {
			vector< pair<int, int> > tmp;
			matrix.push_back(tmp);
		}
		for (int i = 1 ; i <=m ;i++){
			scanf("%d" , &r);
			for (int j = 0 ; j < r ;j++) scanf("%d" , &cols[j]);
			for (int j = 0 ; j < r ;j++){
				scanf("%d" , &value);
				matrix[cols[j] - 1].push_back(make_pair(i, value));
			}
		}
		printf("%d %d\n" , n , m);
		for (int i = 0 ; i < n;i++){
			int sz = matrix[i].size();
			printf("%d" ,sz);
			for (int j = 0 ;j < sz;j++){
				printf(" %d" , matrix[i][j].first );
			}
			printf("\n");
			for (int j = 0 ;j < sz;j++){
				if (j > 0) cout << " ";
				printf("%d" , matrix[i][j].second );
			}
			printf("\n");
		}
	}
	return 0;

}
