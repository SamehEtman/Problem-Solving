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
bool cmp (pair<int,pair<int,int>>v1 , pair<int,pair<int,int>>v2){
	return v1.first * v2.second.first < v2.first*v1.second.first ;
}
int main() {
	int tc;
	scanf("%d" , &tc);
	while (tc--){
		int n;
		scanf("%d" , &n);
		vector <pair<int,pair<int,int>>> v(n);
		for (int i = 0 ; i < n ; i++){
			cin >> v[i].first >> v[i].second.first;
			v[i].second.second = i+1;
		}
		sort(v.begin(), v.end(),cmp);
		for (int i = 0 ; i < n ;i++){
			if (i!=0)cout <<" " <<v[i].second .second ;
			else cout <<v[i].second .second ;
		}
		cout <<endl;
		if (tc) cout <<endl;
	}
	return 0;
}
