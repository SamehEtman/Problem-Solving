#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d ", &n) && n) {
		vector<pair<string,int>> v;
		string temp;
		int x = 0;
		int maxx = 0;
		for (int i = 0 ; i < n ; i++){
			x = 0;
			getline(cin , temp);
			for (int j = 0 ; j < temp.size() ; j++) if (temp[j] == 'X') x++;
			v.push_back(make_pair(temp , x));
			maxx = max(maxx,x);
		}
		int ans = 0;
		for (int i = 0 ; i < v.size() ; i++) {
			if (v[i].second < maxx){
				ans += maxx-v[i].second;
			}
		}
		cout << ans <<endl;
	}
	return 0;

}
