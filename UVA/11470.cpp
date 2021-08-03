#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
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
#include <queue>
#include <set>
#include <map>
#include <iterator>
using namespace std;

int main() {
	int n ,counter = 1;
	while (scanf("%d" , &n) && n){
		int arr[n][n];
		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < n ; j++)
				scanf("%d" , &arr[i][j]);
		printf("Case %d: " , counter++);
		for (int i = 0 ; i < (n+1)/2  ; i++){
			int ans = 0;
			for (int j = i ;j < n-i ; j++){
				for (int k = i ; k < n-i ; k++){
					if (j == i || j == n-i-1){
						ans += arr[j][k];
					}else {
						if (k == i || k == n-i-1){
							ans += arr[j][k];
						}
					}

				}
			}
			if (i < (n+1)/2 -1)cout <<ans << " ";
			else cout << ans <<endl;
		}
	}
	return 0;
}
