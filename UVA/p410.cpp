//greedy technique called load balancing
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <list>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;

int main() {
	int c, s;
	int x = 1;
	while (cin >> c >> s) {
		//if (x != 1) printf("\n");
		vector<int> v(s);
		double avg = 0;
		for (int i = 0; i < s; i++) {
			cin >> v[i];
			avg += v[i];
		}
		avg /=c;
		for (int i = 0; i < 2 * c - s; i++)
			v.push_back(0);
		sort(v.begin(), v.end());
		printf("Set #%d\n", x++);
		double imbalance = 0;
		for (int i = 0; i < c ; i++) {
			printf(" %d:", i);
			if (v[i] != 0) {
				printf(" %d", v[i]);
			}
			if (v[2 * c - 1 - i] != 0) {
				printf(" %d", v[2 * c - 1 - i]);
			}
			imbalance +=abs( v[i] + v[2 * c - 1 - i] - avg);
			printf("\n");
		}
		cout << "IMBALANCE = " ;
		cout <<fixed << setprecision(5)<<imbalance <<endl<<endl;

	}
}
