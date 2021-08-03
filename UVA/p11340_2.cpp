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
int main()
{
	int test ;
	scanf("%d" , &test);
	while (test--){
		double ans = 0;
		int k;
		scanf("%d" , &k);
		vector<pair<char , int>> val;
		while (k--){
			char temp1 ; int temp2;
			cin >>temp1 >> temp2 ;
			val.push_back(make_pair(temp1, temp2));
		}
		int lines ;
		scanf("%d" , &lines);
		lines++;
		while (lines--){
			string temp;
			getline(cin , temp);
			for (int i = 0 ; i < temp.size() ;i++){
				for (int j = 0 ; j < val.size() ; j++){
					if (temp[i] == val[j].first){
						ans += val[j].second;
						break;
					}
				}
			}
		}
		ans/=100;
		cout << fixed << setprecision(2) <<ans << "$\n";
	}
    return 0;
}
