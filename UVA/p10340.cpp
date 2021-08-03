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
	string a ,b;
	while (cin >> a >> b){
		int index = 0;
		int j = 0;
		for (int i = 0 ; i < a.size() ; i++){
			for ( ; j < b.size() ; j++){
				if (a[i] == b[j]){
					index++;
					j++;
					break;
				}
			}
		}
		if (index == a.size()) cout <<"Yes\n";
		else cout <<"No\n";
	}
	return 0;
}
