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
	string s;
	int  before, curr;
	while (cin >> s) {
		before = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'C' || s[i] == 'G' || s[i] == 'J' || s[i] == 'K'
					|| s[i] == 'Q' || s[i] == 'S' || s[i] == 'X' || s[i] == 'Z')
				curr = 2;
			else if (s[i] == 'B' || s[i] == 'F' || s[i] == 'P' || s[i] == 'V')
				curr = 1;
			else if (s[i] == 'D' || s[i] == 'T')
				curr = 3;
			else if (s[i] == 'M' || s[i] == 'N')
				curr = 5;
			else if (s[i] == 'L')
				curr = 4;
			else if (s[i] == 'R')
				curr = 6;
			else
				curr = -1;
			if (curr != before && curr != -1)
				cout << curr;
			before = curr;
		}
		cout << endl;
	}
	return 0;

}
