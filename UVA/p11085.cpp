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
int row[8],queens[8], lineCounter;
bool valid (int r , int c){
	for (int i = 0 ; i <c;i++){
		if (row[i] == r || abs(row[i]-r) == abs(i-c))
			return false;
	}
	return true;
}
int search(int c){
	if (c == 8){
		return 0;
	}
	int tot = 10000;
	for (int r = 0 ; r < 8;r++){
		if (valid(r,c)){
			row[c] = r;
			tot = min (tot , row[c] == queens[c]? search(c+1): 1+search(c+1));
		}
	}
	return tot;
}
int main() {
	while (true) {
		for (int i = 0 ; i < 8;i++){
			if (scanf("%d" , &queens[i])!=1) return 0;
			queens[i]--; row[i] = queens[i];
		}
		printf("Case %d: %d\n" , ++lineCounter , search(0));
	}

}
