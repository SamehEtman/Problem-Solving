#define _CRT_SECURE_nO_WARnInGS
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
	int n ;
	while (scanf("%d" , &n) == 1 , n){
		int arr[n];
		int maximum = 0;
		int sum = 0;
		for (int i = 0 ; i < n ;i++) scanf("%d" , &arr[i]);
		for (int i = 0 ; i < n;i++){
			sum+= arr[i];
			maximum = max(maximum , sum);
			if (sum  <0) sum = 0;
		}
		if (maximum > 0 ) printf("The maximum winning streak is %d.\n" , maximum);
		else printf("Losing streak.\n");
	}
	return 0;
}
