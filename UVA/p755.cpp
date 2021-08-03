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
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		int n;
		scanf("%d", &n);
		vector<string> v;
		for (int z = 0 ; z < n ; z++) {
			string temp1, temp2;
			cin >> temp1;
			for (int i = 0; i < temp1.size(); i++) {
				if (temp1[i] == 'A' || temp1[i] == 'B' || temp1[i] == 'C')
					temp1[i] = '2';
				if (temp1[i] == 'D' || temp1[i] == 'E' || temp1[i] == 'F')
					temp1[i] = '3';
				if (temp1[i] == 'G' || temp1[i] == 'H' || temp1[i] == 'I')
					temp1[i] = '4';
				if (temp1[i] == 'J' || temp1[i] == 'K' || temp1[i] == 'L')
					temp1[i] = '5';
				if (temp1[i] == 'M' || temp1[i] == 'N' || temp1[i] == 'O')
					temp1[i] = '6';
				if (temp1[i] == 'P' || temp1[i] == 'R' || temp1[i] == 'S')
					temp1[i] = '7';
				if (temp1[i] == 'T' || temp1[i] == 'U' || temp1[i] == 'V')
					temp1[i] = '8';
				if (temp1[i] == 'W' || temp1[i] == 'X' || temp1[i] == 'Y')
					temp1[i] = '9';

				if (temp1[i] >= '0' && temp1[i] <= '9') {
					temp2 += temp1[i];
				}
			}
			v.push_back(temp2 );
		}
		sort(v.begin(), v.end());
		int cnt, flag = 0;
		for (int i = 1; i < n; i++) {
			cnt = 1;
			while (i < n && v[i] == v[i - 1]) {
				cnt++;
				i++;
			}
			if (cnt > 1) {
				--i;
				cout << v[i].substr(0, 3) << "-" << v[i].substr(3) << " "
						<< cnt << endl;
				flag = 1;
			}
		}
		if (flag == 0)
			printf("No duplicates.\n");
		if (N > 0)
			cout << endl;
	}
	return 0;

}
