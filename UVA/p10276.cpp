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

int pegsnumber, ans , pegs [50];
bool isPerfectSquare(double x) {
	long double sr = sqrt(x);
	return ((sr - floor(sr)) == 0);
}

void backtrack (int n , int peg){
	if (peg == pegsnumber) return ;
	if (pegs[peg] == 0){
		pegs[peg] = n;
		ans++;
		return backtrack(n+1 , peg);
	}
	for (int i = 0 ; i <= peg ; i++){
		if (isPerfectSquare(double (pegs[i] + n))){
			ans++;
			pegs[i] = n;
			return backtrack(n+1 , peg);
		}
	}
	backtrack(n , peg+1);
}
int main() {
	int tc;
	scanf("%d" , &tc);
	while (tc--){
		ans = 0;
		memset(pegs , 0 , sizeof pegs);
		scanf("%d" , &pegsnumber);
		backtrack(1 , 0);
		cout << ans <<endl;
	}
	return 0;
}
