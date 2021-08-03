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
	cin.ignore();
	while (tc--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		int tmp;
		vector<int> arr;
		while (ss >> tmp)
			arr.push_back(tmp);

		int ans = 1;
		for (int i = 0; i < (int) arr.size(); i++) {
			for (int j = i + 1; j < (int) arr.size(); j++) {
				ans = max(ans, __gcd(arr[i], arr[j]));
			}
		}
		cout << ans << endl;
	}
}

