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

int main() {
	int n;
	scanf("%d", &n);
	cin.ignore();
	while (n--) {
		string line , blank;
		vector<int> vi;
		getline(cin , blank);
		getline(cin , line);
		for (int i = 0 ;i < line.size() ; i++){
			if(line[i] != ' '){
				vi.push_back(line[i] - '0');
			}
		}
		string arr[vi.size() +1];
		getline(cin , line);
		int index = 0;
		for (int i = 0 ; i < line.size(); i++){
			if (line[i] != ' '){
				arr[vi[index]]+=line[i];
			}else {
				index++;
			}
		}
		for (int i = 1 ; i < vi.size() +1 ; i++){
			cout << arr[i]<<endl ;
		}
		if(n>=1) printf("\n");

	}
	return 0;

}
