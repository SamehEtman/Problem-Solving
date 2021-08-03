#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
bitset<20000005> isPrime;
vector<ll> v;
vector<pair<ll, ll>> ans;
void preCalc() {
	isPrime.set();
	isPrime[1] = isPrime[0] = 0;
	for (ll i = 2; i < 20000000; i++) {
		if (isPrime[i]) {
			for (ll j = i * i; j < 20000000; j += i)
				isPrime[j] = 0;
			if (v.size() > 0)
				if (i - v.back() == 2)
					ans.push_back(make_pair(v.back(), i));
			v.push_back(i);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	preCalc();

	while (scanf("%d", &n) == 1) {
		printf("(%lld, %lld)\n" , ans[n-1].first , ans[n-1].second);
	}
}

