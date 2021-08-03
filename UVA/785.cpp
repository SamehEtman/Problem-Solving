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
int br [] = {0 , 0 , 1 , -1};
int bc[] = {-1 , 1 , 0 , 0};
int floodfill(int x, int y, char c) {
	if (x < 0 || x >= arr.size() - 1 || y < 0 || y >= arr[x].size() - 1)
		return 0;
	if (arr[x][y] != ' ')
		return 0;
	arr[x][y] = c;
	int ans = 1;
	for (int i = 0 ; i < 4 ; i++)
			ans += floodfill(x + br[i], y + bc[i] , c);
	return ans;
}
int main() {
	string temp;
	while (getline(cin, temp)) {
		int a, b , c , d;
		arr.clear();
		if (temp.size()){
			arr.push_back(temp);
		}else 			cout << endl;

		while (getline(cin, temp)) {
			arr.push_back(temp);
			if (temp[0] == '_')
				break;
			for (int i = 0; i < arr[arr.size() - 1].size(); i++) {
				if (arr[arr.size() - 1][i] == '#') {
					arr[arr.size() - 1][i] = ' ';
					a = arr.size() - 1;
					b = i;
				}
				if (arr[arr.size() - 1][i] == '/') {
					arr[arr.size() - 1][i] = ' ';
					c = arr.size() - 1;
					d = i;
				}
			}
		}
		floodfill(a, b, '#');
		floodfill(c, d, '/');
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < arr[i].size(); j++)
				cout << arr[i][j];
			cout << endl;
		}
	}

	return 0;
}
