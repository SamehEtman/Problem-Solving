#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <limits>
#include <set>

using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m && (n != 0 || m != 0)){
		int ans = 0;
		set<int> x;
		int temp;
		while (n--){
			cin >> temp;
			x.insert(temp);
		}
		while (m--){
			cin >>temp;
			set<int> ::iterator it;
			it = x.find(temp);
			if (it != x.end()){
				ans++;
			}
		}
		cout <<ans <<endl;
	}
	return 0;
}
