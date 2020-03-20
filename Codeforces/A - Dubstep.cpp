#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main() {
	string x;
	cin >> x;
	string wub = "WUB";
	if (x.size() < 3 && x!= wub){
		cout << x;
		return 0;
	}
	for (int i = 0 ; i < x.size() -2;i++){
		if (x[i] == wub[0] && x[i+1] == wub[1] && x[i+2] == wub[2]){
			x[i] = ' ';
			x[i+1] = ' ';
			x[i+2] = ' ';
		}
	}
	cout << x <<endl;
	return 0;
}