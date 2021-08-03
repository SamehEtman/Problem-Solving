#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <string>
#include <queue>
#include <iterator>
using namespace std;
int main() {
	int tc, counter = 1;
	scanf("%d", &tc);
	while (tc--) {
		stack <char> st;
		string s;
		int ans[30] = {0};
		cin >> s;
		st.push(s[0]);
		for (int i = 1 ; i <(int) s.size() ; i++){
			if (st.top() == s[i]){
				st.pop();
				if (!st.empty()){
					ans[s[i] - 'A']++;
					ans[st.top()-'A']++;
				}
			}else
				st.push(s[i]);
		}
		printf ("Case %d\n" , counter++);
		for (int i = 0 ; i < 27 ; i++){
			if (ans[i]){
				printf("%c = %d\n" , (char)i+'A' , ans[i]);
			}
		}

	}
	return 0;
}
