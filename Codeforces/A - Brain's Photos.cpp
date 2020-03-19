#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
	int n,m;
	cin >>n >>m;
	char arr[n+1][m+1];
	for (int i = 0 ; i < n;i++){
		for (int j =0 ; j < m ; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 'C' || arr[i][j] == 'M' ||arr[i][j] == 'Y'){
				cout << "#Color\n";
				return 0;
			}
		}
	}
	cout << "#Black&White\n";
	return 0;
}
 