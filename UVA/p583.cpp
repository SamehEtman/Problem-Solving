#include<bits/stdc++.h>

using namespace std;
#define ll long long
int mod = 1e9 + 7;

vector<int> v, ans;
bitset<50000> isPrime;

void preCalc() {
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for (ll i = 2; i*i <= 2147483648; i++) {
		if (isPrime[i]) {
			for (ll j = i * i; j *j<= 2147483648; j += i)
				isPrime[j] = 0;
			v.push_back(i);
		}
	}
}

void solve(int n) {
	int idx = 0, pf = v[0];
	while (pf * pf <= n ) {
		while (n % pf == 0) {
			n /= pf;
			ans.push_back(pf);
		}
		idx++;
		if (idx > (int)v.size() - 1) break;
		pf = v[idx];
	}
	if (n != 1) ans.push_back(n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	preCalc();
	while (cin >> n) {

		if (n == 0)
			break;
		ans.clear();

		solve (abs(n));

		if (n < 0) printf("%d = -1 x " , n);
		else printf("%d = " , n);

		for (int i = 0 ; i < (int)ans.size() ; i++){
			if (i == (int) ans.size() - 1) printf("%d" , ans[i]);
			else printf("%d x " , ans[i]);
		}
		printf("\n");
	}
	return 0;
}
