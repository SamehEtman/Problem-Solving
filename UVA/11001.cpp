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
#include <sstream>
#include <string>
#include <iterator>
using namespace std;

int main() {
	double vt, v0;
	while (cin >> vt >> v0 && vt && v0) {
		double maxl = 0.0, max = 0.0;
		for (int i = 1;; i++) {
			double v = vt / i;
			if (v <= v0)
				break;
			double d = 0.3 * sqrt(v - v0);
			double temp = d * i;
			if (temp >= maxl) {
				if (fabs(temp - maxl) <= 1e-12) {
					maxl = 0;
					max = 0;
					break;
				}
				maxl = temp;
				max = i;
			}
		}
		cout << max <<endl;
	}
	return 0;
}
