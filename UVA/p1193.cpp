#include <iostream>
#include <vector>
#include <string>
#include <map>
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
	int n , d;
	int counter = 1;
	while (scanf("%d %d " , &n , &d)){
		if (n==0 && d == 0)break;
		vector <pair<double,double>>v;
		bool flag = 0;
		for (int i = 0 ; i < n ; i++){
			double a , b;
			cin >> a >>b;
			if (b > d) flag = 1;
			double x = sqrt(d*d-b*b);
			v.push_back(make_pair(a-x,a+x));
		}
		if (flag == 1){
			 printf("Case %d: %d\n", counter++, -1);
			continue;
		}
		sort(v.begin() , v.end());
		int i = 0 ,ans = 0;
		double r = -(1e+30);
		while (i < n ){
			while (i < n && v[i].first <=r){
				r = min (r , v[i].second);
				i++;
			}
			r = v[i].second;
			ans++;
		}
        printf("Case %d: %d\n", counter++, ans-1);

	}
	return 0;
}
