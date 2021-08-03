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
#define ull unsigned long long

int main() {
	int k;
	set<int> marks;
	marks.insert(0);
	for (int i = 1; i <= 20; i++) {
		marks.insert(i);
		marks.insert(2 * i);
		marks.insert(3 * i);
	}
	marks.insert(50);
	vector<int> scores;
	for (set<int>::iterator it = marks.begin(); it != marks.end(); it++) {
		scores.push_back(*it);
	}
	while (cin >> k && k > 0) {
		set<set<int>> combinations;
		for (int a = 0; a < scores.size() && scores[a] <= k; a++) {
			for (int b = 0; b < scores.size() && scores[a] + scores[b] <= k;
					b++) {
				for (int c = 0;
						c < scores.size()
								&& scores[a] + scores[b] + scores[c] <= k;
						c++) {
					set<int> combination;
					if (scores[a] + scores[b] + scores[c] == k) {
						combination.insert(a);
						combination.insert(b);
						combination.insert(c);
						combinations.insert(combination);
					}
				}
			}
		}
		int permutations = 0;
		for (set<set<int> >::iterator i = combinations.begin();i!=combinations.end();++i) {
		      if ((*i).size()==1) {
		        permutations++;
		      } else if ((*i).size()==2) {
		        permutations+=3;
		      } else if ((*i).size()==3) {
		        permutations+=6;
		      }
		}
		 if (combinations.size()>0) {
		      cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<k<<" IS "<<combinations.size()<<"."<<endl;
		      cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<k<<" IS "<<permutations<<"."<<endl;
		    } else {
		      cout<<"THE SCORE OF "<<k<<" CANNOT BE MADE WITH THREE DARTS."<<endl;
		    }
		    for (int i=0;i<70;++i) cout<<"*";
		cout<<endl;
	}
	 cout<<"END OF OUTPUT"<<endl;
	return 0;
}
