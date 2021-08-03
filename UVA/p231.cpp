#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <iterator>
using namespace std;


int main(){
	int n , counter =1;
	while (scanf("%d" , &n)){
		if (n == -1) break;
		if (counter > 1) cout << endl;

		vector <int> v = {n};
		while (scanf("%d" , &n)){
			if (n == -1) break;
			v.push_back(n);
		}
		vector<int> d (v.size() , 1);
		int ans = 1;
		for(int i = 0 ; i < (int)v.size() ; i++){
			for (int j = 0 ; j < i ; j++){
				if (v[i] <= v[j]){
					d[i] = max (d[i] , d[j]+1);
					ans = max (ans , d[i]);
				}
			}
		}

		printf("Test #%d:\n  maximum possible interceptions: %d\n" , counter++ , ans);
	}

     return 0;
}
