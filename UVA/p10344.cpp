#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <string>
#include <queue>
#include <iterator>
using namespace std;
bool visited[5];
bool possible = 0;
int arr[5];
void backtrack(int lenght, int value, bool first) {
	if (possible)
		return;
	if (lenght == 5) {
		possible = (23 == value);
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (visited[i])
			continue;
		visited[i] = 1;
		if (!first) {
			backtrack(lenght + 1, value + arr[i], 0);
			backtrack(lenght + 1, value - arr[i], 0);
			backtrack(lenght + 1, value * arr[i], 0);
		} else {
			backtrack(lenght + 1, arr[i], 0);
		}
		visited[i] = 0;
	}
}
int main() {
	while (true){
		possible = 0;
		bool flag = 0;
		for (int i = 0 ; i < 5 ; i++){
			scanf("%d" , &arr[i]);
			if (arr[i] != 0) flag = 1;
		}
		if (!flag){
			break;
		}else{
			backtrack(0,0,1);
		}
		if (possible) printf("Possible\n");
		else printf("Impossible\n");
	}
	return 0;
}
