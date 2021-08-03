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
	int a, b, c;
		for (a = 1; 4 * a <= 2000; a++) {
			if (pow(a,4) > 2*pow(10,9)) break;
			for (b = a; a + 3 * b <= 2000; b++) {
		        if (a*pow(b,3) > 2*pow(10,9)) break;
				for (c = b; a + b + 2 * c <= 2000; c++) {
		            if (a*b*pow(c,2) > 2*pow(10,9)) break;
					long long p = (a * b * c);
					long long s = (a + b + c);

					if (p <= 1000000)
						continue;
					if ((int)(1000000 * s) / (p - 1000000) != (double)(1000000 * s) / (p - 1000000)) continue;
					long long d = (1000000 * s) / (p - 1000000);
					if (d < c || s + d > 2000  || p*d > 2*pow(10,9))
						continue;

					if (fabs((a + b + c + d) / 100.0 - (a * b * c * d) / 100000000.0) < 1e-9) {
						printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", a / 100.0,
								b / 100.0, c / 100.0, d / 100.0);
					}
				}

			}
	}
	return 0;
}
