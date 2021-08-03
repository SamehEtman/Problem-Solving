#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
	int n ;
	scanf("%d \n", &n);
	char input[35];
	while (n--){
		map <string, double> x;
		double total = 0;
		while (gets(input) && strlen(input)){
			x[input]++;
			total++;
		}
		map<string, double>::iterator it;
		for (it = x.begin(); it != x.end(); it++) {
			printf("%s %.4lf\n", (*it).first.data(),
				(double)(*it).second / (double)total * 100.0);
		}
		if (n > 0){
			printf("\n");
			//x.clear();
		}
	}

	return 0;
}
