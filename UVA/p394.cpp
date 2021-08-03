#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
#include <math.h>
#include <cstdio>
#include <stack>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Array {
public:
	string name;
	int base_address;
	int element_size;
	int num_dimensions;
	vector<int> lower_bounds;
	vector<int> upper_bounds;
	vector<int> constants;
};
int main() {
	int n, r;
	scanf("%d %d", &n, &r);
	Array arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].name >> arr[i].base_address >> arr[i].element_size
				>> arr[i].num_dimensions;
		for (int j = 0; j < arr[i].num_dimensions; j++) {
			int upper, lower;
			cin >> lower >> upper;
			arr[i].lower_bounds.push_back(lower);
			arr[i].upper_bounds.push_back(upper);
			arr[i].constants.push_back(0);
		}
		arr[i].constants.push_back(0);
		arr[i].constants[arr[i].num_dimensions] = arr[i].element_size;
		for (int j = arr[i].num_dimensions - 1; j >= 1; j--) {
			arr[i].constants[j] = arr[i].constants[j + 1] * (arr[i].upper_bounds[j] - arr[i].lower_bounds[j] + 1) ;
		}
		arr[i].constants[0] = arr[i].base_address;
		for (int j = 1 ; j <= arr[i].num_dimensions ;j++){
			arr[i].constants[0] -= arr[i].constants[j] * arr[i].lower_bounds[j-1];
		}

	}
	for (int i = 0 ; i < r ; i++){
		string name;
		cin >> name;
		for (int j = 0 ; j < n; j++){
			if (name == arr[j].name){
				cout << name << "[";
				int result = arr[j].constants[0];
				for (int k =0; k < arr[j].num_dimensions ; k++){
					if (k!= 0) cout << ", ";
					int dimension;
					cin >> dimension;
					cout << dimension;
					result += arr[j].constants[k+1] * dimension;
				}
				cout << "] = ";
				cout << result << endl;
			}
		}

	}
	return 0;

}
