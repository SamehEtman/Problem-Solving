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
	string x;
	//cout << char(9-('7'-'0') + '0');
	cin >> x;
	for (int i = 0; i < x.size(); i++) {
		if (9 - (x[i] - '0') < (x[i] - '0') ) {
			if (i != 0) {
				x[i] = 9 - (x[i] - '0') + '0';
			}
			else{
				if(9 - (x[i] - '0') > 0){
					x[i] = 9 - (x[i] - '0') + '0';
				}
			}
		}
	}
	cout << x << endl;
	return 0;
}