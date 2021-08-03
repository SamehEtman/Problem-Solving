#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<int> v;
bitset<1000005> isPrime;

void preCalc() {
	isPrime.set();
	isPrime[1] = isPrime[0] = 0;
	for (ll i = 2; i < 1000000; i++) {
		if (isPrime[i]) {
			for (ll j = i * i; j < 1000000; j += i)
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
	while (scanf("%d", &n)) {
		if (!n)
			break;
		bool flag = 0;
		for (int i = 0; i < (int) v.size(); i++) {
			if (isPrime[v[i]] && isPrime[n - v[i]]) {
				flag = 1;
				printf("%d = %d + %d\n", n, v[i], n-v[i]);
				break;
			}
		}
		if (flag)
			continue;
		printf("Goldbach's conjecture is wrong.\n");
	}
}
