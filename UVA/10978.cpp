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
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		string card, num;
		string cards[n] = { };
		int fill = -1;
		int add = 0;
		for (int i = 0; i < n; i++) {
			cin >> card >> num;
			add = 0;
			int temp = num.size();
			int index = fill + 1;
			while (temp > 0) {
				if (!cards[index %n].empty()) {
					add++;
				} else {
					temp--;
				}
				index++;

			}
			fill += num.size() + add;
			cards[(fill) % n] = card;
		}
		cout << cards[0] ;
		for (int i = 1; i < n; i++)
			cout <<" " << cards[i] ;
		printf("\n");
	}
	return 0;
}
