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
#define ull unsigned long long

int main() {
	int c;
	cin >>c;
	while (c--){
		int n;
		cin >> n ;
		int grid[n][n];
		int roworder[n];
		for (int i = 0 ; i < n;i++) roworder[i] = i;
		for (int i = 0 ; i < n;i++)
			for (int j = 0 ; j<n;j++)
				cin >> grid[i][j];
		int ans = 10000000;
		do{
			int total = 0;
			for (int i =0;i <n;i++){
				int temp = roworder[i];
				total += grid[temp][i];
			}
			ans = min(ans , total);
		}
		while (next_permutation (roworder, roworder+n));


		cout << ans <<endl;
	}
	return 0;
}
