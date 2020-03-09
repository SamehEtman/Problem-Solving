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
			"asdfghjkl"
			"zxcvbnm";
	string x;
	int n;
	cin >>n;
	cin >>x;
	for (int i = 0 ; i <n;i++){
		k[k.find(tolower(x[i]))] = '.';
	}
	for (int i = 0 ; i <k.size() ;i++){
		if(k[i] != '.'){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}