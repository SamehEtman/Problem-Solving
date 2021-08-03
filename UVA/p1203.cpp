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
	string r;
	int qnum, t;
	priority_queue<pair <int, pair<int,int>> > pq;
	while (cin >> r && r != "#") {
		cin >> qnum >> t;
		pq.push(make_pair(-t, make_pair(-qnum , -t)));
	}
	int k ;
	cin >>k;
	for (int i = 0 ; i < k;i++){
		cout << -pq.top().second.first <<endl;
		pair<int , pair<int,int>> temp = pq.top();
		pq.pop();
		temp.first+=temp.second.second;
		pq.push(temp);
	}
	return 0;
}
