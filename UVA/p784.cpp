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
int n, m;
vector<string> arr;
int floodfill(int x, int y) {
	if (x < 0 || x >= arr.size()-1 || y < 0 || y >= arr[x].size()-1)
		return 0;
	if (arr[x][y] != ' ')
		return 0;
	arr[x][y] = '#';
	int ans = 1;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			ans += floodfill(x + i, y + j);
	return ans;
}
int main() {
	int tc;
	scanf("%d\n", &tc);
	while (tc--) {
		string temp;
		int a, b;
		arr.clear();
		while (getline(cin, temp)) {
			arr.push_back(temp);
			if (temp[0] == '_')
				break;
			for (int i = 0; i < arr[ arr.size() - 1].size(); i++) {
				if (arr[arr.size() - 1][i] == '*') {
					arr[arr.size() - 1][i] = ' ';
					a = arr.size() - 1;
					b = i;
				}
			}
		}
		floodfill(a,b);
		for (int i = 0 ; i < arr.size() ; i++){
			for (int j = 0 ;j < arr[i].size() ; j++)
				cout << arr[i][j];
			cout <<endl;
		}
	}

	return 0;
}
