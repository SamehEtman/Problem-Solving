#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main() {
	long long x , y ,n;
	cin >> x >> y >> n;
	cout << ((x + n - 1) / n ) * ((y + n - 1) / n) <<endl;
	return 0;
}