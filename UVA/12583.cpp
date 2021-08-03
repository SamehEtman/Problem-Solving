//o(n^2) just simulation
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
	int N;
	scanf("%d" , &N);
	int counter = 1;
	while (N--){
		printf("Case %d: " , counter++);
		int n , k;
		scanf("%d %d" , &n , &k);
		string s;
		cin >> s;
		int ans = 0;
		for (int i = 0 ;i < n   ; i++){
			for (int j = i+1 ; j <= min(k + i , n-1) ; j++){
				if (s[i] == s[j]){
					ans++;
					break;
				}
			}
		}
		printf("%d\n" , ans);
	}
	return 0;
}
