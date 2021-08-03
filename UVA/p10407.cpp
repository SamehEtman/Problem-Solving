#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n) {
		if (n == 0) break;
		vector <int > v;
		v.push_back(n);
		while (cin >> n){
			if (n == 0) break;
			v.push_back(n);
		}
		for (int i= 1 ;i <(int) v.size() ; i++){
			v[i] -= v[0];
		}
		int ans = v[1];
		for (int i = 1; i < (int)v.size() ; i++){
			ans = __gcd(ans , v[i]);
		}
		cout << abs(ans) << endl;
	}
}

