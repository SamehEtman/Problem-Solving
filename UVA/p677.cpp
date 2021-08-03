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
int n, m;
int grid[15][15] , path[15];
int visited[15] , max_num ;
void dfs(int v , int len){
	path[len] = v+1;
	if (len == n){
		max_num ++;
		printf("(%d" , path[0]);
		for (int j = 1 ; j <= len ; j++){
			printf(",%d" , path[j]);
		}
		printf(")\n");
		return ;
	}
	for (int i = 0 ; i < m ; i++){
		if (!visited[i] && grid[i][v]){
			visited[i] = 1;
			dfs(i,len+1);
			visited[i] = 0;
		}
	}
}
int main() {
	while (scanf("%d %d", &m, &n)) {

		max_num = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++)
				scanf("%d", &grid[i][j]);
			visited[i] = 0;
		}
		visited[0] = 1;
		dfs(0,0);
		if (max_num == 0){
			printf("no walk of length %d\n" , n);
		}
		if (scanf("%d" , &n) == EOF){
			break;
		}else cout <<endl;
	}
	return 0;
}
