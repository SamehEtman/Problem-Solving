#define _CRT_SECURE_NO_WARNINGS
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
int edges [65536];
int sum [65536];
int main()
{
	int N;
	while (scanf("%d" , &N) != EOF){
		int edge_num = pow(2,N);
		for (int i = 0 ; i < edge_num ;i++){
			scanf("%d" , &edges[i]);
		}
		for (int i = 0 ; i < edge_num;i++){
			int edge_sum = 0;
			for (int j = 0 ; j < N;j++){
				int b = i^(1<<j);
				edge_sum += edges[b];
			}
			sum[i] = edge_sum;
		}
		int max_ans = 0;
		for (int i = 0 ; i < edge_num;i++){
			for (int j = 0 ; j < N;j++){
				int b = i^(1<<j);
				max_ans = max (max_ans , sum[i]+sum[b]);
			}
		}
		printf("%d\n" , max_ans);
	}
    return 0;
}
