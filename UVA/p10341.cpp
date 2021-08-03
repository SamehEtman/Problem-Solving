#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <math.h>
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
#define EPS 1e-9
int p, q, r, s, t, u;
double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}
double bisection(){
  double lo = 0, hi = 1;
  while (lo + EPS < hi){
    double x = (lo+hi)/2;
    if (f(lo) * f(x) <= 0){
      hi = x;
    } else {
      lo = x;
    }
  }
  return (lo+hi)/2;
}
int main() {
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		if (f(0) * f(1) > 0) {
			puts("No solution");
		} else {
			printf("%.4lf\n", bisection());
		}
	}
	return 0;
}
