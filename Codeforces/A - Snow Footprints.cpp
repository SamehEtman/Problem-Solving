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
	int n;
	cin >> n;
	cin >> x;
	int s , t;
	bool first = 1 , last = 1;
	for (int i = 0 ; i < n-1;i++){
		if (first && x[i] == 'R' ){
			s = i+1;
			first = 0;
		}
		if (x[i] == 'R' && x[i+1] =='L'){
			t = i+1;
			last = 0;
		}
	}
	if (!first && last){
		for (int i = 0 ; i< n ; i++){
			if (x[i] == 'R') t = i+2;
		}
	}else if(first) {
		for (int i = 0 ; i < n ; i++){
			if (x[i] == 'L' && first){
				t = i;
				first = 0;
			}
			if(x[i] == 'L'){
				s = i+1;
			}
 
		}
	}
	cout << s << " " << t <<endl;
	return 0;
}