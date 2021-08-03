#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main() {
	ll N, U, L, ans;
	while (scanf("%lld %lld %lld", &N, &L, &U) != EOF) {
		ans = 0;
		for (int i = 31 ; i >=0;i--){
			ll state = N & 1LL <<i;
			if (state){
				ll temp = state -1;
				temp|=ans;
				if (temp < L) ans|=state;
			}else {
				ll temp = ans;
				temp|=1LL<<i;
				if (temp <= U) ans=temp;
			}
		}
		printf("%lld\n" , ans);
	}
	return 0;
}
