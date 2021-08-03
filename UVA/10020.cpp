#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <list>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;

int main() {
	int t;
	scanf("%d" , &t);
	while (t--){
		int m , n=0;
		scanf ("%d" , &m);
		vector <pair <int,int>> v;
		int a , b;
		while (cin >> a >> b ){
			if (a ==0 && b ==0)break;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin() , v.end());
		vector <pair <int , int>> segments;
		int currentl = n , nextl = 1;
		int i = 0 ;
		while (n <m){
			//cout << nextl <<endl;
			int last = -1;
			for (;i < v.size() ; i++){
				if (v[i].first > currentl){
					break;
				}else if (v[i].second >= nextl){
					nextl = v[i].second;
					last = i;
				}
			}
			if (last ==-1) break;
			n = currentl = nextl;
			segments.push_back(make_pair(v[last].first, v[last].second));
		}
		if (segments.size() != 0 && n >=m){
			cout << segments.size() <<endl;
			for (int i =0 ; i < segments.size() ; i++){
				cout << segments[i].first <<" " <<segments[i].second <<endl;
			}
		}else  cout <<0 <<endl;
		if (t) cout <<endl;
	}
}
