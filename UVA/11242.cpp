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
	int f, r;
	while (cin >> f >> r, f) {
		double arrf[1000];
		double arrr[1000];
		multiset<double> v;
		for (int i = 0 ; i < f;i++) cin >> arrf[i];
		for (int i = 0 ; i < r ;i++) cin >> arrr[i];
		for (int i = 0 ;i <r;i++){
			for (int j = 0 ; j <f;j++){
				v.insert(- (arrr[i]/arrf[j]));
			}
		}
		multiset<double> ::iterator it = v.begin();
		double maximum = -1;
		for ( ;  ;it++){
			it++;
			if (it == v.end() ) break;
			double temp = *it;
			it--;
			maximum = max(maximum , *it / temp);
		}
			cout << fixed <<setprecision(2) << maximum <<endl;
	}
	return 0;
}
