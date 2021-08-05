#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	int counter = 1;
	while (tc--) {
		ll n;
		cin >> n;
		ll a = 1;
		int arr[n];
		ll b = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			a *= arr[i];
		}
		for (int i = 0; i < n; i++) {
			b += a / arr[i];
		}
		a *= n;
		printf("Case %d: %lld/%lld\n", counter++, a / __gcd(a, b), b / __gcd(a, b));
	}

}

