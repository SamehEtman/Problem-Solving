#define _CRT_SECURE_nO_WARnInGS
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <limits>
#include <set>
#include <iomanip>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		long long arr[A][B][C];
		for (int i = 0; i < A; i++)
			for (int j = 0; j < B; j++)
				for (int k = 0; k < C; k++) {
					long long g; cin>>g;
					      if (i>0) g+=arr[i-1][j][k];
					      if (j>0) g+=arr[i][j-1][k];
					      if (k>0) g+=arr[i][j][k-1];
					      if (i>0 && j>0) g-=arr[i-1][j-1][k];
					      if (j>0 && k>0) g-=arr[i][j-1][k-1];
					      if (i>0 && k>0) g-=arr[i-1][j][k-1];
					      if (i>0 && j>0 && k>0) g+=arr[i-1][j-1][k-1];
					arr[i][j][k]=g;
				}
		long long ans = INT_MIN;
		for (int i = 0; i < A; i++)
			for (int j = 0; j < B; j++)
				for (int k = 0; k < C; k++)
					for (int i1 = i; i1 < A; i1++)
						for (int j1 = j; j1 < B; j1++)
							for (int k1 = k; k1 < C; k1++) {
								long long temp = arr[i1][j1][k1];
								if (i > 0)
									temp -= arr[i - 1][j1][k1];
								if (j > 0)
									temp -= arr[i1][j - 1][k1];
								if (k > 0)
									temp -= arr[i1][j1][k - 1];
								if (i > 0 && j > 0)
									temp += arr[i - 1][j - 1][k1];
								if (j > 0 && k > 0)
									temp += arr[i1][j - 1][k - 1];
								if (i > 0 && k > 0)
									temp += arr[i - 1][j1][k - 1];
								if (i > 0 && j > 0 && k > 0)
									temp -= arr[i - 1][j - 1][k - 1];
								if (temp > ans)
									ans = temp;
							}
		cout << ans <<endl;
		if (tc) printf("\n");

	}
	return 0;
}
