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
int main(){
	int n;
	int counter = 1;
	while (scanf("%d" , &n) != EOF){
		printf("Case #%d: " , counter++);
		int arr[n];
		for (int i = 0 ; i < n ; i++){
			scanf("%d" , &arr[i]);
		}
		long long maxi = 0;
		for (int i = 0 ; i < n ; i ++){
			long long prod = 1;
			for (int j = i ; j < n ; j++){
				prod *=arr[j];
				maxi = max(maxi , prod);
			}
		}
		printf("The maximum product is %lld.\n\n" , maxi);
	}

	return 0;
}
