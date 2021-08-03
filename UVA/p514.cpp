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
	int N;

	while (cin >> N , N){
		while (true){
			stack <int> st;
			int j =0;
			for (int i = 0 ;i <N;i++){
				int c ;
				cin >> c;
				if (c==0) goto back;
				while (j <N){
					if (st.size() > 0 && st.top() == c) break;
					j++;
					st.push(j);
				}
				if (st.top() == c) st.pop();
			}
			if (st.empty()) cout <<"Yes\n";
			else cout <<"No\n";
		}
		back:
		cout <<endl;
	}
	return 0;
}
