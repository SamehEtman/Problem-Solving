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
int grid [3][3];
void func (){
	int h [3][3];
	h[0][0] = (grid[0][1] + grid[1][0]) %2;
	h[0][1] = (grid[0][0] + grid[1][1] + grid[0] [2]) %2;
	h[0][2] = (grid[0][1] + grid[1][2]) %2;

	h[1][0] = (grid[0][0] + grid[1][1] + grid[2] [0]) %2;
	h[1][1] = (grid[0][1] + grid[1][0] + grid[1] [2]+ grid[2][1]) %2;
	h[1][2] = (grid[0][2] + grid[1][1] + grid[2] [2]) %2;

	h[2][0] = (grid[1][0] + grid[2][1] ) %2;
	h[2][1] = (grid[2][0] + grid[1][1] + grid[2] [2]) %2;
	h[2][2] = (grid[2][1] + grid[1][2] ) %2;

	for (int i = 0 ; i < 3 ; i++)
		for (int j = 0 ; j < 3;j++)
			grid[i][j] = h[i][j];
}
bool is_zero(){
	for (int i = 0 ; i < 3;i++){
		for (int j = 0 ; j < 3 ; j++){
			if (grid[i][j] > 0) return 0;
		}
	}
	return 1;
}
int main()
{
	int test ;
	scanf("%d" , &test);
	while (test--){
		for (int i = 0 ; i < 3 ; i++)
			for (int j = 0 ; j < 3 ;j++)
				scanf("%1d" , &grid[i][j]);
		int ans = -1;
		while (!is_zero()){
			func();
			ans++;
		}
		printf("%d\n" , ans);
	}
    return 0;
}
