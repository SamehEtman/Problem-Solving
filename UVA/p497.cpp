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

int main() {
	int tc;
	scanf("%d" , &tc);
	getchar();
	cin.ignore();
	while (tc--) {
		string s;
		vector<int> v;
		while (getline(cin, s)) {
			if (s.size() == 0)
				break;
			int tmp = stoi(s);
			v.push_back(tmp);
		}
		int n = (int) v.size();
		vector<int> d(n , 1) , p(n,-1);
		for (int i = 0 ;i < n ; i++){
			for (int j = 0 ; j < i ; j++){
				if (v[i] > v[j] && d[i] < d[j]+1){
					d[i] = d[j]+1;
					p[i] = j;
				}
			}
		}
		int pos = 0 ,  maxi = 1;
		for (int i = 0 ; i < n ; i++){
			if (d[i] > maxi){
				maxi = d[i];
				pos = i;
			}
		}
		printf("Max hits: %d\n" , maxi);
		stack <int> st;
		while (pos != -1){
			st.push(v[pos]);
			pos = p[pos];
		}
		for (int i = 0 ; i < maxi ; i++){
			printf("%d\n" , st.top());
			st.pop();
		}
		if (tc)printf("\n");

	}

	return 0;
}
