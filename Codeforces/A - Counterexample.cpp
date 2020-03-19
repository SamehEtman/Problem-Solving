#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
	long long x, y;
	cin >> x >> y;
	if (x % 2 != 0)
		x++;
	if (y - x + 1 < 3) {
		cout << -1;
		return 0;
	}
	cout << x << " " << x + 1 << " " << x + 2 << endl;
	return 0;
}