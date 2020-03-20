#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main() {
	string a = "Tetrahedron";
	string b = "Cube";
	string c = "Octahedron";
	string d = "Dodecahedron";
	string e = "Icosahedron";
	int n ;
	cin >> n;
	long long sum = 0;
	for (int i = 0 ; i < n;i++){
		string x;
		cin >> x ;
		if (x == a) sum+=4;
		if (x == b) sum+=6;
		if (x == c) sum+=8;
		if (x == d) sum+=12;
		if (x == e) sum+=20;
	}
	cout << sum <<endl;
	return 0;
}
