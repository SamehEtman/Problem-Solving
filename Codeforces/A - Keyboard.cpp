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
	string k = "qwertyuiop"
			"asdfghjkl;"
			"zxcvbnm,./";
	char d;
	cin >> d;
	char x;
	if (d =='R'){
		while(cin >> x){
			int i =k.find(x);
			cout << k[i-1];
		}
	}else {
		while(cin >> x){
					int i =k.find(x);
					cout << k[i+1];
				}
	}
	return 0;
}