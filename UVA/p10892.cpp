#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	while (cin >> n) {
		if (!n)
			break;
		int sq = sqrt(n);
		vector<int> v;
		for (int i = 1; i <= sq; i++) {
			if (n % i == 0) {
				if (n / i == i)
					v.push_back(i);
				else {
					v.push_back(i);
					v.push_back(n / i);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < (int) v.size(); i++) {
			for (int j = i; j < (int) v.size(); j++) {
				int lcm = v[i] / __gcd(v[i], v[j]) * v[j];
				if (lcm == n)
					ans++;

			}
		}
		cout << n << " " << ans << endl;
	}

}

