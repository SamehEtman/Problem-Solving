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
	while (cin >> n){
		stack <int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool st = true , qu = true , perque = true , enter = true;

		for(int i = 0 ; i <  n ; i++){
			int op , val;
			cin >> op >> val;

			if (op == 1){
				s.push(val);
				q.push(val);
				pq.push(val);
			}
			if (s.size() == 0 && enter) {
				enter = 0;
				cout << "impossible\n";
			}
			if (op == 2 && enter){
				int temp ;
				temp = s.top();
				if (temp != val) st = false;
				temp = q.front();
				if (temp != val) qu = false;
				temp = pq.top();
				if (temp != val) perque = false;
				s.pop();q.pop();pq.pop();
			}
		}
		if (enter)
		if (!st && !qu && !perque) cout << "impossible\n";
		else if (st==1 && qu ==0 && perque ==0) cout << "stack\n";
		else if (st==0 && qu ==1 && perque ==0) cout << "queue\n";
		else if (st==0 && qu ==0 && perque ==1) cout << "priority queue\n";
		else cout << "not sure\n";
	}
	return 0;
}
