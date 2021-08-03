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
struct tl {
	double l;
	int g, y, r;
};
bool isgreen(tl x, int speed) {
	double time = x.l * 3600 / speed;
	time = fmod(time, x.g + x.y + x.r);
	return time <= x.g + x.y;
}
bool isvalid(int speed, vector<tl> &x) {
	for (int i = 0; i < x.size(); i++) {
		if (!isgreen(x[i], speed)) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int n;
	int counter = 1;
	while (scanf("%d", &n) && n != -1) {
		printf("Case %d: ", counter++);
		vector<tl> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].l >> v[i].g >> v[i].y >> v[i].r;
		}
		vector<int> validspeeds;
		for (int i = 30; i <= 60; i++) {
			if (isvalid(i, v)) {
				validspeeds.push_back(i);
			}
		}
		if (validspeeds.empty()) {
			printf("No acceptable speeds.\n");
			continue;
		}
		for (int i = 0; i < validspeeds.size(); i++) {
				if (validspeeds[i] == validspeeds[i + 1] - 1) {
					cout << validspeeds[i] << "-";
					while (true) {
						//i++;
						if (validspeeds[i] != validspeeds[i + 1] - 1) {
							cout << validspeeds[i];
							if (i < validspeeds.size() - 1)
								printf(", ");
							break;
						}
						i++;
						if (i == validspeeds.size() - 1) {
							cout << validspeeds[i];
							break;
						}
					}
				} else {
					cout << validspeeds[i];
					if (i < validspeeds.size() - 1)
						printf(", ");
				}
		}
		cout << endl;
	}
	return 0;
}
