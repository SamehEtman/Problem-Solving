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
	int n ;
	while (cin >> n , n){
		priority_queue<int> pq;
		for (int  i = 0 ; i < n ;i++){
			int temp; cin >>temp;
			pq.push(-temp);
		}
		long long sum = 0;
		for (int i = 0 ; i < n-1 ;i++){
			int n1 = -pq.top();
			pq.pop();
			int n2 = -pq.top();
			pq.pop();
			int c = n1 + n2;
			sum+=c;
			pq.push(-c);
		}
		cout <<sum <<endl;
	}
	return 0;
}
