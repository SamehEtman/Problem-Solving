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
	int sum;
	int counter = 1;
	while (scanf("%d", &sum) && sum >= 0) {
		printf("Case %d:\n" , counter++);
		int arr[12];
		for (int i = 0 ; i < 12;i++){
			scanf("%d" , &arr[i]);
		}
		for (int i = 0 ;i < 12;i++){
			int now;
			scanf("%d" , &now);
			if (sum >= now){
				printf("No problem! :D\n");
				sum+=arr[i] - now;
			}else{
				printf("No problem. :(\n");
				sum+=arr[i];
			}
		}
	}
	return 0;

}
