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
	int n;
	cin >> n;
	string x;
	cin >> x;
	bool flag = 0;
	for (int i = 0; i < x.size() - 1; i++) {
		if (x[i] == 'R' && x[i + 1] == 'L') {
			flag = true;
			break;
		}
	}
	if (!flag) {
		cout << -1;
		return 0;
	}
	int arr[n + 1];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int mini = INT_MAX;
	int temp;
	for (int i = 0; i < n - 1; i++) {
		if (x[i] == 'R' && x[i+1] == 'L') {
			temp = (arr[i+1] - arr[i]) / 2;
			mini = min(mini, temp);
		}
	}
	cout << mini << endl;
	return 0;
}
 