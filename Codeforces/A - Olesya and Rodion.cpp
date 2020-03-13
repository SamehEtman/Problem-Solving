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
	int n, t;
	cin >> n >> t;
	string ans = "";
	if (t == 10) {
		if (n == 1) {
			cout << -1;
			return 0;
		} else {
			for (int i = 0; i < n; i++) {
				if (i == n - 1)
					ans.push_back('0');
				else
					ans.push_back('1');
			}
		}
	}else {
		for (int i = 0 ; i < n ; i++){
			ans.push_back('0' + t);
		}
	}
	cout << ans <<endl;
	return 0;
}
 