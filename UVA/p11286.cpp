//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n, n){
		map <string, int> frosh;
		int maxN = -1;
		for (int i = 0; i < n; i++){
			string x[5];
			cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
			sort(x, x + 5);
			string code;
			for (int i = 0; i < 5; i++) code += x[i];
			if (frosh.count(code)){
				frosh[code]++;
				maxN = max(maxN, frosh[code]);
			}
			else {
				frosh[code]++;
				maxN = max(maxN, 1);
			}
		}
		int count = 0;
		map<string, int> ::iterator it = frosh.begin();
		for (; it != frosh.end(); ++it)
		if (it->second == maxN) count += it->second;
		cout << count << endl;
	}
	return 0;
}
