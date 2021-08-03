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
	int k;
	while (cin >>k){
		vector<pair<int,int>> v;
		for (int i = k+1 ; i<=2*k;i++){
			if ((double)i*k / (i-k) == (int) i*k / (i-k))
				v.push_back(make_pair(i*k / (i-k) , i));
		}
		cout << v.size()<<endl;
		for (int i = 0 ; i <v.size();i++){
			printf("1/%d = 1/%d + 1/%d\n" , k , v[i].first , v[i].second);
		}
	}
	return 0;
}
