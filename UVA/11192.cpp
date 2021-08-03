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
using namespace std;
int main() {
	int g ;
	string x;
	while (scanf("%d" , &g) && g){
		cin >> x;
		string op;
		int add = x.size()/g;
		for (int i = 0 ; i < x.size() ; i+=add){
			for (int j = i+add-1 ; j>=i ;j--){
				op+=x[j];
			}
		}
		cout << op <<endl;
	}
	return 0;

}
