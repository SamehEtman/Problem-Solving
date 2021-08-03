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
#include <limits>
#include <set>

using namespace std;
int main()
{
	int d;
	while (cin >> d && d !=0){
		multiset<int> x;
		int n;
		long long counter = 0;
		while (d--){
			cin >> n;
			while (n--){
				int temp;
				cin >>temp;
				x.insert(temp);
			}
			multiset<int> ::iterator it;
			it = x.end();it--;
			counter += *it - *(x.begin());
			//cout << "counter is : " << *it - *(x.begin()) <<endl;
			x.erase(it);
			x.erase(x.begin());
		}
		cout << counter <<endl;
	}
	return 0;
}
