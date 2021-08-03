#include<bits/stdc++.h>
using namespace std;
#define ll long long
int l, u;
bitset<1000005> isPrime;
vector <ll> v;
void preCalc() {
	isPrime.set();
	isPrime[1] = isPrime[0] = 0;
	for (ll i = 2; i < 50000; i++) {  //sqrt (2147483647) is about 46,341 so 50000 is a reasonable number
		if (isPrime[i]) {
			for (ll j = i * i; j < 50000; j += i)
				isPrime[j] = 0;
			v.push_back(i);
		}
	}
}

bool is_prime(ll n) {
	if (n < 50000)
		return isPrime[n];
	else {
		int sq = sqrt(n);
		for (ll i = 0; i <= (ll) v.size() && v[i] <= sq; i++) {
			if (n % v[i] == 0) return 0;
		}
	}
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	preCalc();
	while (scanf("%d %d", &l, &u) == 2) {
		if (l == 0 && u ==0) break;
		ll a, b, c, d;
		ll close = 2147483647, dist = -close;
		ll prev = -1, sol = 0;
		for (ll i = l; i <= u; i++) {
			if (is_prime(i)) {
				if (prev == -1)
					prev = i;
				else {
					if (i - prev < close) {
						close = i - prev;
						a = prev;
						b = i;
					}
					if (i - prev > dist) {
						dist = i - prev;
						c = prev;
						d = i;
					}
					prev = i;
					sol = 1;
				}
			}
		}
		if (sol)
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", a, b, c, d);
		else
			printf("There are no adjacent primes.\n");
	}
}

