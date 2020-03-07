// the key is to notice that the maximum array number is less than n
// so if u already know if the third number exists or not
// take 2 0 1 3 4 as an example
// take 2 and 1 u know the third number is 0 but it's already taken
// take 1 and 3 u know the third number is 5 but it's not there caust it's not less than n
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
	int n ;
	while (scanf("%d:" , &n) && n){
		int arr[n];
		for (int i = 0 ; i < n ; i++){
			cin >>arr[i];
		}
		bool flag = 1;
		for (int i = 0 ; i < n; i++){
			bool before [10000]= {0};
			for (int j = 0 ; j <= i ; j++){
				before[arr[j]] = 1;
			}
			for (int j = i+1 ; j < n-1 ;j++	){
				before[arr[j]] = 1;
				int nxt = arr[j] + (arr[j] - arr[i]);
				if (nxt >= 0 && nxt < n){
					if(!before[nxt]){
						printf("no\n");
						flag = 0;
						break;
					}
				}
			}
			if (!flag) break;
		}
		if (flag) printf("yes\n");
	}
	return 0;
}
