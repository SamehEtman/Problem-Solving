

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
typedef pair<int, int> ii;
typedef vector<ii> vii;
bool visited [30][30];
vector <vector<int>> adj;
char s[20];
int n , h;
void backtrack (int i , int m){
	if (m > i || m < 0) return ;
	if (!i){
		s[n] = '/0';
		puts(s);
		return ;
	}
	s[n-i] = '0';
	backtrack (i-1 , m);
	s[n-i] = '1';
	backtrack(i-1 , m-1);
}
int main() {
	int tc;
	scanf("%d" , &tc);
	while (tc--){
		scanf("%d %d" , &n , &h);
		string s;
		s.assign(n , '0');
		for (int i = n-1 ; i > n-h-1 ; i--){
			s[i] = '1';
		}
		do{
			cout << s <<endl;
		}while (next_permutation(s.begin() , s.end()));

		if (tc) cout <<endl;


	}

	return 0;
}
