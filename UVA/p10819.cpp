#define _CRT_SECURE_nO_WARnInGS
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
int M[150] , F[150];
int n , m;
int memo [150][150000];
int solve (int id , int spent ){
	if (spent > m && m < 1800) return -10000;
	if (spent > m+200) return -10000;
	if (id == n){
		if (spent > m && spent <=2000) return -10000;
		return 0;
	}
	if (memo[id][spent] != -1) return memo[id][spent];
	return memo[id][spent] = max (solve (id+1 , spent) , F[id] + solve (id+1 , spent + M[id]));
}

int main() {
	while (scanf("%d %d" , &m  ,&n) ==2){
		memset(memo , -1 , sizeof memo);
		for (int i = 0 ; i < n ;i++)scanf("%d %d" , &M[i] , &F[i]);
		printf("%d\n" , solve(0 , 0));
	}

	return 0;
}
