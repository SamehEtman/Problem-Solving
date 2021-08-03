// o(n^2) simulation
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
	scanf("%d" , &n);
	while (n--){
		int r ;
		scanf("%d" , &r);
		int arr[r];
		int ans=  2147483647;
		for (int i = 0 ; i < r ; i++) scanf("%d" , &arr[i]);
		for (int i = 0 ; i < r ; i++){
			int sum = 0;
			for (int j = 0 ; j < r; j++	){
				if (i == j) continue;
				sum += abs(arr[i] - arr[j]);

			}
			ans = min (ans , sum);
		}
		printf("%d\n" , ans);
	}
	return 0;
}
