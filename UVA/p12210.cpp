#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;
#define MAX 10100
int store[MAX];

int main() {
	int b , s;
	int tc = 1;
	while (cin >> b >> s , b ,s){
		int bs[b];
		int ss[s];
		for (int i = 0 ; i < b;i++) cin >> bs[i];
		for (int i = 0 ; i < s;i++) cin >>ss[i];
		sort(bs , bs+b);
		if (b <= s) printf ("Case %d: 0\n" ,tc++ );
		else if (b > s) printf("Case %d: %d %d\n" , tc++ , b - s, bs[0]);

	}
	return 0;
}
