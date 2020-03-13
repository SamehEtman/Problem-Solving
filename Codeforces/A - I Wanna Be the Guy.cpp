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
	int n ;
	int p ,q ;
	int arr[101] = {-1};
	cin >> n;
	cin >> p ;
	for (int i = 0 ; i < p ; i++){
		int level ;
		cin >> level ;
		arr[level] = 1;
	}
	cin >> q;
	for (int i = 0 ; i < q ; i++){
			int level ;
			cin >> level ;
			arr[level] = 1;
		}
	for (int i = 1 ; i <=n; i++){
		if (arr[i] !=1){
			cout << "Oh, my keyboard!\n";
			return 0;
		}
	}
	cout << "I become the guy.\n";
	return 0;
}