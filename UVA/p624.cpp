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
int arr[30];
int main() {
	int n;
	while (scanf("%d" , &n) == 1){
		int m;
		scanf("%d" , &m);
		vector <int> vans;
		long long ans = 0;
		for (int i = 0 ; i < m;i++) scanf("%d" , &arr[i]);
		for (int i = 0 ; i < (1<<m);i++){
			long long sum = 0;
			vector <int> nums;
			for (int j = 0 ; j < m;j++){
				if (i & (1<<j)){
					sum += arr[j];
					nums.push_back(arr[j]);
				}
			}
			if (sum > ans && sum <=n){
				ans = sum;
				vans = nums;
			}else if (sum == ans && sum <=n && nums.size() > vans.size()){
				ans = sum;
				vans = nums;
			}
		}
		for (int i = 0 ; i < (int)vans.size() ; i++) printf("%d " , vans[i]);
		printf("sum:%lld\n",ans);
	}
	return 0;
}
