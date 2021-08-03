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
#define ull unsigned long long

int main() {
	int t ;
	cin >>t ;
	while (t--){
		int n ;
		cin >> n;
		int arr[1010];
		for (int i = 1 ;i <=n;i++) cin >> arr[i];
		int count = 0;
		for (int i = 2 ; i <=n;i++){
			for (int j = i-1;j>=1;j--	){
				if (arr[i] >=arr[j]) count++;
			}
		}
		cout << count <<endl;
	}
	return 0;
}
