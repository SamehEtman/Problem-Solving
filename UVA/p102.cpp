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
	unsigned int arr[9];

	while (cin >> arr[0]) {
		for (int i = 1; i < 9; i++)
			cin >> arr[i];

		unsigned int mini = 1 << 31;
		string s = "BGC";

		if (arr[3] + arr[6] + arr[2] + arr[8] + arr[1]
				+ arr[4] < mini) {
			s = "BCG";
			mini = arr[3] + arr[6] + arr[2] + arr[8] + arr[1]
					+ arr[4];
		}
		if (arr[3] + arr[6] + arr[1] + arr[7] + arr[2]
				+ arr[5] < mini) {
			s = "BGC";
			mini = arr[3] + arr[6] + arr[1] + arr[7] + arr[2]
					+ arr[5];
		}
		if (arr[5] + arr[8] + arr[0] + arr[6] + arr[1]
				+ arr[4] < mini) {
			s = "CBG";
			mini = arr[5] + arr[8] + arr[0] + arr[6] + arr[1]
					+ arr[4];
		}
		if (arr[5] + arr[8] + arr[1] + arr[7] + arr[0]
				+ arr[3] < mini) {
			s = "CGB";
			mini = arr[5] + arr[8] + arr[1] + arr[7] + arr[0]
					+ arr[3];
		}
		if (arr[4] + arr[7] + arr[0] + arr[6] + arr[2]
				+ arr[5] < mini) {
			s = "GBC";
			mini = arr[4] + arr[7] + arr[0] + arr[6] + arr[2]
					+ arr[5];
		}
		if (arr[4] + arr[7] + arr[2] + arr[8] + arr[0]
				+ arr[3] < mini) {
			s = "GCB";
			mini = arr[4] + arr[7] + arr[2] + arr[8] + arr[0]
					+ arr[3];
		}
		cout << s << " " << mini << endl;
	}
	return 0;
}
