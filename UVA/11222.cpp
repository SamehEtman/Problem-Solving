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
	int t;
	scanf("%d", &t);
	for (int z = 1; z <= t; z++) {
		int solved[10000] = { 0 };
		int num[3], p[3][1000];
		for (int i = 0; i < 3; i++) {
			scanf("%d", &num[i]);
			for (int j = 0; j < num[i]; j++) {
				scanf("%d", &p[i][j]);
				solved[p[i][j]]++;
			}
			sort(p[i], p[i] + num[i]);
		}
		int maximum = 0 , special[3]={0};
		for (int i = 0; i < 3; i++) {
			int temp = 0;
			for (int j = 0; j < num[i]; j++) {
				if (solved[p[i][j]] == 1)
					temp++;
			}
			if (temp >= maximum){
				maximum = temp;
				special[i] = maximum;
			}
		}
		printf("Case #%d:\n", z);
		for (int i = 0; i < 3; i++) {
			if (special[i] == maximum) {
				printf("%d %d", i + 1, maximum);
				for (int j = 0; j < num[i]; j++) {
					if (solved[p[i][j]] == 1) {
						printf(" %d", p[i][j]);
					}
				}
				printf("\n");
			}
		}

	}
	return 0;
}
