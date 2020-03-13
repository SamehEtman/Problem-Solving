#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
using namespace std;
struct dice {
	int fleft ;
	int bleft ;
	int fright ;
	int bright ;
	int up ;
	int down ;
};
int main() {
	int n ;
	cin >> n;
	vector<dice> v(n);
	int up;
	cin >>up;
	v[0].up = up;
	v[0].down =7- up;
	for (int i = 0  ; i < n ; i++){
		int fleft , fright;
		cin >> fleft >> fright ;
		v[i].fleft = fleft;
		v[i].bleft = 7 - fleft;
		v[i].fright = fright;
		v[i].bright = 7 - fright;
	}
	for (int i = 1 ; i < n; i ++){
		if (v[i-1].down == v[i].fleft || v[i-1].down == v[i].bleft || v[i-1].down == v[i].fright || v[i-1].down == v[i].bright){
			cout << "NO\n";
			return 0;
		}else {
			v[i].up = v[i-1].down;
			v[i].down = 7-v[i].up;
		}
	}
	cout << "YES\n";
	return 0;
}
 