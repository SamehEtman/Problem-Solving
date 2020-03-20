#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main() {
	int n ;
	cin >> n;
	char arr[n+1][n+1];
	string x="01" ;
	for (int i = 0 ; i < n; i++){
		for (int j = 0 ; j < n; j++){
			cin >> arr[i][j];
		}
	}
	x[0] = arr[0][0];x[1] = arr[0][1];
	if (n ==1 || x[0] == x[1]){
		cout << "NO\n";
		return 0;
	}
	for (int i = 0 ; i < n; i++){
			for (int j = 0 ; j < n; j++){
				if (i==j || i == n-j -1){
					//cout << i << "  " << "  " << n-j-1<<endl;
					if (arr[i][j] != x[0]){
						cout << "NO\n";
						return 0;
					}
				}else {
					if (arr[i][j] != x[1]){
						cout << "NO\n";
						return 0;
				}
				}
			}
		}
	cout << "YES\n";
	return 0;
}