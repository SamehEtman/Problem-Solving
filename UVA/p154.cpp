// just simulate the process 
// using 3 nested loops
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
	int index[300];
	index['r'] = 0;
	index['o'] = 1;
	index['y'] = 2;
	index['g'] = 3;
	index['b'] = 4;
	string s;
	char city[100][5];
	int n = 0;
	while (getline(cin, s) && s[0] != '#') {
		if (s[0] != 'e') {
			for (int i = 0; i < 5; i++) {
				city[n][index[s[i * 4]]] = s[i * 4 + 2];
			}
			n++;
		} else {
			int min = (1<<31) -1;
			int sum = 0 , ans = 0;
			for (int i = 0 ;i  < n ; i++){
				sum = 0;
				for (int j = 0 ; j < n ; j++){
					for (int k = 0 ; k < 5 ; k++){
						if (city[i][k] != city[j][k]){
							sum++;
						}
					}
				}
				if (sum < min){
					min = sum;
					ans = i;
				}
			}
			printf("%d\n" , ans+1);
			n = 0;
		}
	}
	return 0;
}
