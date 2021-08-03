#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <math.h>
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
#define ull unsigned long long
#define EPS 1e-9
int n , m;
int arr[1000000];
bool is_valid(int max_cap){
	int curr = 0 , curr_cap = 0;
	for (int i = 0 ; i < n;i++){
		if (arr[i] > max_cap) return false;
		if (curr_cap + arr[i] > max_cap){
			curr_cap = 0;
		}
		if (curr_cap == 0) curr++;
		curr_cap += arr[i];
		if (curr > m) return 0;
	}
	return true;
}
int main() {
	while (scanf("%d %d" , &n , &m) != EOF){
		int hi =0;
		for (int i = 0 ; i < n;i++){
			scanf("%d" , &arr[i]);
			hi +=arr[i];
		}
		int lo = 1 ;

		int best;
		while (hi-lo >=0){

			int mid = (hi+lo)/2;

			if (is_valid(mid)){
				hi = mid-1;
				best = mid;
			}else {
				lo = mid+1;
			}
		}
		cout << best <<endl;
	}
	return 0;
}
