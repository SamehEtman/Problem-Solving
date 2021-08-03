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
	int tc;
	scanf("%d" , &tc);
	int counter = 1;
	while (tc--){
		int n , p , q;
		scanf("%d %d %d",&n,&p,&q);
		int weight = 0 , num = 0;
		int arr[n];
		for (int i = 0 ; i < n ; i++){
			scanf("%d" , &arr[i]);
			weight +=arr[i];
			if (weight <= q && num < p){
				num ++;
			}
		}
		printf ("Case %d: %d\n" , counter++ , num);
	}
	return 0;
}
