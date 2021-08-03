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
int n, w[30], c;
int outc() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if ((c / w[i]) % n == (c / w[j]) % n) {
				c = min((c / w[i] + 1) * w[i], (c / w[j] + 1) * w[j]);
				return 0;
			}
		}
	}
	return 1;
}
int main() {
	string line;
	while (getline(cin, line)) {
		n = 0 ;
		istringstream ss(line);
		string word;
		while (ss >> word) {
			w[n] = 0;
			for (int i = 0; i < word.size(); i++) {
				w[n] = (w[n] << 5) + (word[i] - 'a' + 1);
			}
			n++;
		}
		c = 2147483647;
		for (int i = 0; i < n; i++) {
			c = min(c, w[i]);
		}
		while (!outc());
		cout << line <<endl;
		printf("%d\n\n", c);
	}
	return 0;
}
