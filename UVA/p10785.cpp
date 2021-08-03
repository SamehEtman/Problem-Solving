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
	int N;
	int counter = 1;
	scanf("%d", &N);
	vector<pair<int, char>> con;
	vector<pair<int, char>> vowl;
	int ind = 1;
	for (char i = 'A'; i <= 'Z'; i++) {
		if (ind % 10 == 0)
			ind++;
		if (i == 'A' || i == 'E' || i == 'O' || i == 'I' || i == 'U') {
			vowl.push_back(make_pair(ind % 10, i));
		} else {
			con.push_back(make_pair(ind % 10, i));
		}
		ind++;
	}
	sort(vowl.begin(), vowl.end());
	sort(con.begin(), con.end());
	while (N--) {
		int n;
		scanf("%d", &n);
		int vindex = 0, cindex = 0, vcont = 0, ccont = 0;
		string so , se;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				if (vcont == 21) {
					vcont = 0;
					vindex++;
				}
				so.push_back(vowl[vindex].second);
				vcont++;
			} else {
				if (ccont == 5) {
					ccont = 0;
					cindex++;
				}
				se.push_back(con[cindex].second);
				ccont++;
			}
		}
		sort(so.begin(),so.end());
		sort(se.begin(),se.end());
		string op;
		for (int i = 0 ; i < max(so.size() , se.size()) ; i++){
			if (i< so.size())op.push_back(so[i]);
			if (i< se.size())op.push_back(se[i]);
		}
		printf("Case %d: " , counter++);
		cout << op <<endl;
	}
	return 0;
}
