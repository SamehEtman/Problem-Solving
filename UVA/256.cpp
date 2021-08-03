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
		vector <int> v;
		for (int i = 0 ;i <= 9999 ; i++)
			v.push_back(i*i);
		int n;
		while (scanf("%d" , &n) != EOF){
			for (int i = 0 ; i < v.size() ; i++){
				if (v[i] >=pow(10,n)) break;
				int l = v[i] / pow(10 , n/2);
				int r = v[i] % (int)pow(10 , n/2);
				if ((l+r)* (l+r) == v[i]){
					cout << setw(n) << setfill('0') << v[i] <<endl;
				}
			}
		}
	    return 0;
}
