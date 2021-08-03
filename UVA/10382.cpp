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
	int n , l, w;
	while (scanf("%d %d %d" , &n , &l , &w) != EOF){
		vector <pair <double,double>> v;
		for (int i = 0 ; i < n; i++){
			double p , r;
			cin >> p >>r;
			if (pow(r,2) >= pow((w/2.0),2))
			v.push_back(make_pair(p- sqrt(pow(r,2) - pow((w/2.0),2)), p+ sqrt(pow(r,2) - pow((w/2.0),2))));
		}
		sort(v.begin() , v.end());
		//for (int i = 0 ;i < n; i++) cout <<v[i].first << " "<< v[i].second <<endl;
		vector <pair <double,double>> segments;
		double currentl = 0 , nextl = 1;
		int i = 0 ;
		while (currentl <l){
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
			 currentl = nextl;
			segments.push_back(make_pair(v[last].first, v[last].second));
		}
		if (segments.size() != 0 && currentl >=l){
			cout << segments.size() <<endl;

		}else  cout <<-1 <<endl;
	}
}
