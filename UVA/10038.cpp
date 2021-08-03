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
	int N;
	while (scanf("%d", &N) != EOF) {
		bool flag = 1;
		int arr[N];
		bool h[3000] = { 0 };
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 0; i < N - 1; i++) {
			h[abs(arr[i + 1] - arr[i])] = 1;
			//cout << abs(arr[i + 1] - arr[i]) <<endl;
		}
		for (int i = 1; i < N ; i++) {
			//cout << i << " " << h[i] << endl;
			if (h[i] != 1){
				printf("Not jolly\n");
				flag = 0;
				break;
			}

		}
		if (flag) printf("Jolly\n");
	}
	return 0;
}
