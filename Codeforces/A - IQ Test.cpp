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
	char arr[4][4];
	for (int i = 0 ; i < 4 ; i++){
		cin >> arr[i];
	}
	int white =0, black=0 ;
	for (int i = 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3 ; j++){
 
			for (int k = 0 ; k  < 2 ; k++){
				for (int l = 0 ; l < 2 ; l++){
					if(arr[i+k][j+l] == '.') white++;
					if(arr[i+k][j+l] == '#') black++;
				}
			}
			if (white >=3 || black >=3) {
				cout << "YES\n";
				return 0;
			}else {
				white = 0;
				black = 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}