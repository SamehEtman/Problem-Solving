//either u take the fastest with two slowest or the two fastest alone and the two slowest alone
//u choose the faster method
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
	while (tc--){
		stringstream ss;
		int n ;
		scanf("%d" , &n);
		vector <int> v (n);
		for (int i =0 ; i < n;i++)scanf("%d" , &v[i]);
		sort(v.begin()  , v.end());
		int ans = 0;
		int index = n-1;
		while (index >=3){
			int t1 = 2*v[1] + v[0] + v[index];
			int t2 = 2*v[0] + v[index] + v[index -1];
			if (t2 > t1){
				ans +=t1;
				ss << v[0] <<" "<< v[1]<<endl << v[0] << endl <<v[index-1] <<" " <<v[index]<<endl << v[1] <<endl;
			}else {
				ans +=t2;
				ss <<v[0] << " " << v[index]<<endl <<v[0]<<endl << v[0] <<" " << v[index-1] <<endl <<v[0] <<endl;
			}
			index -=2;
		}
		if (index == 2){
			ans +=v[0] + v[index]+v[1];
			ss << v[0] << " " << v[index] <<endl << v[0] << endl << v[0] <<" "<< v[1]<<endl;
		}else if (index == 1){
			ans +=v[index];
			ss << v[0] << " "<< v[index] <<endl;
		}else {
			ans +=v[0];
			ss <<v[0]<<endl;
		}
		cout <<ans <<endl << ss.str() ;
		if (tc) cout <<endl;
	}
	return 0;
}
