
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
using namespace std;

int main() {
	int n;
	int counter = 1;
	while (scanf("%d", &n) && n) {
		printf("Set #%d\n" , counter++);
		int arr[n] ;
		int ans  = 0;
		int sum = 0;
		for (int i = 0 ; i < n; i++){
			cin >>arr[i];
			sum+= arr[i];
		}
		int avg = sum /n;
		for (int i = 0 ; i < n ; i++){
			if (arr[i] > avg){
				ans +=arr[i]-avg;
			}
		}
		printf("The minimum number of moves is %d.\n" , ans);
		printf("\n");
	}
	return 0;

}
