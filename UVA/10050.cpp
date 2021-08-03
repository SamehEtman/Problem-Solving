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
	scanf("%d" , &n);
	while (n--) {
		int N, days;
		scanf("%d" , &days);
		scanf("%d" , &N);
		int sum =0;
		bool done[4000] = {};
		for (int i = 0 ; i < N;i++){
			int h;
			scanf("%d" , &h);
			for (int j = h ; j<= days; j+=h){

				if(j%7 != 0 && j%7 != 6){
					if(done[j] != 1){
						sum++;
					}
					done[j] =1;
				}
			}
		}
		printf("%d\n" , sum);
	}
	return 0;

}
