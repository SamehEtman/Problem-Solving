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
	int tc,counter = 1;
	scanf("%d", &tc);
	while (tc--) {
		int n, m, l;
		scanf("%d %d %d", &n, &m, &l);
		vector <pair <int, string>> ans;
		for (int i = 0; i < l; i++) {
			string temp, name, tmp;
			int a, b, indx;
			cin >> temp;
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i] == ':') {
					for (int j = 0; j < i; j++)
						name += temp[j];
					indx = i + 1;
				}
				if (temp[i] == ',') {
					for (int j = indx; j < i; j++)
						tmp += temp[j];
					a = stoi(tmp);
					cin.clear();
					tmp.clear();
					for (int j = i + 1; j < temp.size(); j++)
						tmp += temp[j];
					b = stoi(tmp);
					break;
				}
			}
			int units = n, mini = 0;
			while (units > m) {
				if (units / 2 >= m) {
					if ((units - (units / 2)) * a > b) {
						//half
						mini += b;
						units = units / 2;
					} else {
						mini += a * (units - m);
						units = m;
					}
				} else {
					mini += a * (units - m);
					units = m;
				}
				//cout << units <<"  " << mini <<endl;
			}
			ans.push_back(make_pair(mini , name));
		}
		sort(ans.begin(), ans.end());
		printf("Case %d\n" , counter++);
		for (int i = 0 ; i < ans.size() ; i++){
			cout << ans[i].second << " " << ans[i].first<<endl;
		}
	}
	return 0;
}
