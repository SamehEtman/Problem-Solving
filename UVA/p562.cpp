#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <iterator>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int dp1[102][25001];
int dp2[102][25001];

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		int arr[n + 1];
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		int hsum1 = sum / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= hsum1; j++) {
				if (arr[i] > j) {
					dp1[i][j] = dp1[i - 1][j];
				} else {
					dp1[i][j] = max(dp1[i - 1][j],
							arr[i] + dp1[i - 1][j - arr[i]]);
				}
			}
		}
		int hsum2 = sum - dp1[n][hsum1];

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= hsum2; j++) {
				if (arr[i] > j) {
					dp2[i][j] = dp2[i - 1][j];
				} else {
					dp2[i][j] = max(dp2[i - 1][j],
							arr[i] + dp2[i - 1][j - arr[i]]);
				}
			}
		}


		printf("%d\n", abs(dp1[n][hsum1] - dp2[n][hsum2]));
	}
	return 0;

}



/*#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <iterator>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int dp1[102][25001];
int dp2[102][25001];

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		int arr[n + 1];
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		int hsum1 = sum / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= hsum1; j++) {
				if (arr[i] > j) {
					dp1[i][j] = dp1[i - 1][j];
				} else {
					dp1[i][j] = max(dp1[i - 1][j],
							arr[i] + dp1[i - 1][j - arr[i]]);
				}
			}
		}
		//int hsum2 = sum - dp1[n][hsum1];

	//	for (int i = 1; i <= n; i++) {
	//		for (int j = 1; j <= hsum2; j++) {
	//			if (arr[i] > j) {
	//				dp2[i][j] = dp2[i - 1][j];
	//			} else {
	//				dp2[i][j] = max(dp2[i - 1][j],
	//						arr[i] + dp2[i - 1][j - arr[i]]);
	//			}
	//		}
	//	}
 	//

		printf("%d\n", abs(sum - dp1[n][hsum1] *2 ));
	}
	return 0;

}
 */
