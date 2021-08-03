#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<int> v;
bitset<35005> isPrime;

void preCalc() {
	isPrime.set();
	isPrime[1] = isPrime[0] = 0;
	for (ll i = 2; i < 35000; i++) {
		if (isPrime[i]) {
			for (ll j = i * i; j < 35000; j += i)
				isPrime[j] = 0;
			v.push_back(i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	preCalc();
	while (cin >> n) {
		if (!n)
			break;
		//set <pair<int , int>> st;
		ll ans = 0;
		for (int i = 0; i < (int) v.size() && v[i] <= n/2; i++) { // v[i] <= n/ 2 to avoid recalculations
			if (n - v[i] < 0)
				break;
			if (isPrime[v[i]] && isPrime[n - v[i]]) {
				ans++;
				//st.insert(make_pair(min(v[i] , n - v[i]) , max(v[i] , n - v[i])));
			}
		}
		cout << ans << endl;
	}
}
