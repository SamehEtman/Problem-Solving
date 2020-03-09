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
	int n;
	cin >> n;
	int arr[n+1];
	for (int i = 0 ;i < n ; i++) cin >>arr[i];
	for (int i = 0 ; i < n ; i++){
		if (i==0){
			cout << abs(arr[i+1] - arr[i]) << " " << abs (arr[n-1] - arr[i]) <<endl;
		}else if (i == n-1){
			cout << abs (arr[n-1] - arr[n-2]) << " " << abs(arr[n-1] - arr[0]) <<endl;
		}else{
			cout << min (abs(arr[i+1] - arr[i]) , abs (arr[i] - arr[i-1])) << " " << max (abs(arr[i] - arr[0]) , abs(arr[n-1] - arr[i])) <<endl;
		}
	}
	return 0;
}
 