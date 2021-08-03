// just simulation 
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
	int n;
	while (scanf("%d", &n) != EOF) {
		int arr1[n], arr2[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr1[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr2[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int temp , loc;
			for (int j = i ; j < n; j++) {
				if (arr2[i] == arr1[j]) {
					temp = arr1[j];
					loc = j;
					break;
				}
			}
			for (int j = loc; j > i; j--) {
				arr1[j] = arr1[j - 1];
				ans++;
			}
			arr1[i] = temp;

		}
		printf("%d\n" , ans);
	}
	return 0;
}
