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
	int n, b, d;
	cin >> n >> b >> d;
	int arr[n + 1];
	int o = 0, ans = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		if (arr[i] > b)
			continue;
		else {
			o += arr[i];
			if (o > d) {
				ans++;
				o = 0;
			}
		}
	}
	cout <<ans <<endl;
	return 0;
}