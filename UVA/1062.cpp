#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <bitset>
#include <limits>
#include <set>
using namespace std;
int main() {
	string cont;
	int t = 0;
	while (cin >>cont && cont != "end"){
		t++;
		int count = 1;
		vector <stack <char>> s;
		s.push_back(stack <char>());
		s[0].push(cont[0]);
		for (int i = 1 ; i <cont.size();i++){
			bool flag = true;
			for (int j = 0 ; j < s.size();j++){
				if (cont[i] <= s[j].top()){
					s[j].push(cont[i]);
					flag = false;
					break;
				}
			}
			if (flag){
				s.push_back(stack <char>());
				s[s.size()-1].push(cont[i]);
				count++;
			}

		}
	/*	for (int j = 0 ; j < s.size();j++){
			int x = s[j].size();
						for (int k = 0 ; k < x;k++){
							cout << s[j].top() << "  ";
							s[j].pop();
						}
						cout <<endl;
					}*/
        printf("Case %d: %d\n", t, count);	}
	return 0;
}
