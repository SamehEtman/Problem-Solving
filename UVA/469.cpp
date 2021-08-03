#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
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
#include <queue>
#include <set>
#include <iterator>
using namespace std;
vector<vector<int>> adj;
bool visited[100];
char arr[30][30];
int n;
vector <string> temp;
int floodfill(int x , int y){
	if (x >= (int)temp.size() || x <0 || y >= (int)temp[0].size() || y <0) return 0;
	if (temp[x][y] != 'W') return 0;
	temp[x][y] = '.';
	int ans = 1;
	for (int i = -1 ; i <= 1;i++){
		for (int j = -1 ; j <=1 ; j++)
		ans += floodfill(x+i , y+j);
	}
	return ans ;
}
int main() {
	int tc;
	scanf("%d\n" , &tc);
	while (tc--){
		string tmp;
		vector <pair<int,int>> q;
		vector <string> vs;
		while (getline(cin,tmp)){
			if (tmp.size() == 0){
				break;
			}else if (isdigit(tmp[0])){
				stringstream ss ;
				ss << tmp;
				int a , b;
				ss >> a >> b;
				q.push_back(make_pair(a,b));
			}else
				vs.push_back(tmp);
		}
		for (int i =0 ; i < (int)q.size() ; i++){
			temp = vs;
			cout << floodfill(q[i].first-1 , q[i].second-1) <<endl;
		}
		if (tc) cout <<endl;
	}
	return 0;
}
