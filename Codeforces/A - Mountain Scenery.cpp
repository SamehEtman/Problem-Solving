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
	int n , k;
	cin >> n >> k;
	int size = (n*2) +1;
	int arr[(n*2) +2];
	for (int i = 0 ; i < size ; i++){
		cin >> arr[i];
	}
	for (int i = 1 ; i < size -1 && k >0; i+=2){
		if (arr[i]-1 > arr[i-1] && arr[i]-1 > arr[i+1]){
			arr[i]--;
			k--;
		}
	}
	for (int i = 0 ; i < size ; i++){
			cout << arr[i] <<" ";
		}
	return 0;
}
 