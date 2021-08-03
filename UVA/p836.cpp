#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <iterator>
using namespace std;
string ss[30];
int arr[30][30];
int main() {
	int tc;
	scanf("%d", &tc);
	cin.ignore();
	getchar();
	while (tc--) {
		string s;
		int idx = 0;

		while (getline(cin, s)) {
			if (s.size() == 0)
				break;
			ss[idx] = s;
			idx++;
			int sum = 0;
			for (int i = 1; i <= (int) ss[idx - 1].size(); i++) {
				sum += ss[idx - 1][i - 1] - '0';
				arr[idx][i] = arr[idx - 1][i] + sum;
			}
		}

		/*for (int i = 0; i < idx; i++) {
			for (int j = 0; j < idx; j++)
				cout << arr[i][j] << "	";
			cout << endl;
		}*/
		int sum = 0;

		for (int i = 1; i <= idx; i++)
			for (int j = 1; j <= idx; j++)
				for (int k = i; k <= idx; k++)
					for (int l = j; l <= idx; l++) {
						if (arr[k][l] - arr[k][j - 1] - arr[i - 1][l]
								+ arr[i - 1][j - 1]
								== (k - i + 1) * (l - j + 1)) {
							sum =max (sum , (k - i + 1) * (l - j + 1));
						}
					}

		cout << sum << endl;
		if (tc)
			cout << endl;
		

	}
	return 0;
}
