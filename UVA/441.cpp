#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <limits>
#include <set>
#include <iomanip>
using namespace std;
int main() {
	int k;
	int i = 0;
	while (cin >> k, k){
		if (i == 1){
			cout <<endl;
		}
		int S[k];
		for (int i = 0; i < k; i++) // input: k sorted integers
			scanf("%d", &S[i]);
		for (int i = 0 ; i < (1 << k);i++){
			for (int j = 0 ; j < k;j++){
				if (i & (1 << j)){
					cout << S[j]<< " ";
				}
			}
			cout << endl;
		}
		i = 1;

	}
	return 0;
}
