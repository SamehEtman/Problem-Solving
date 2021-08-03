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
	vector<pair<string, pair<string, int>>> books;
	string s;
	while (true) {
		string name;
		string by;
		string author;
		char c;
		cin >> c;
		if (c == '"') {
			string syl;
			while (cin >> syl) {
				if (syl[syl.size() - 1] == '"') {
					name += syl;
					name.erase(name.end() - 1, name.end());
					break;
				} else {
					name += syl;
					name += " ";
				}
			}
		} else {
			cin >> c >> c;
			break;
		}
		cin >> by;
		getline(cin, author);
		books.push_back(make_pair(author, make_pair(name, -1)));
	}
	sort(books.begin(), books.end());
	string state;
	while (true) {
		cin >> state;
		string name;
		char c;
		if (state == "END") {
			break;
		}
		if (state != "SHELVE") {
			cin >> c;
			if (c == '"') {
				string syl;
				while (cin >> syl) {
					if (syl[syl.size() - 1] == '"') {
						name += syl;
						name.erase(name.end() - 1, name.end());
						break;
					} else {
						name += syl;
						name += " ";
					}
				}
			}
		}
		if (state == "BORROW") {
			for (int i = 0; i < books.size(); i++) {
				if (books[i].second.first == name) {
					books[i].second.second = 0;
				}
			}
		} else if (state == "RETURN") {
			for (int i = 0; i < books.size(); i++) {
				if (books[i].second.first == name) {
					books[i].second.second = 1;
				}
			}
		} else if (state == "SHELVE") {
			for (int i = 0; i < books.size(); i++) {
				if (books[i].second.second == 1) {
					bool flag = 1;
					for (int j = i - 1; j >= 0; j--) {
						if (books[j].second.second != 0) {
							cout << "Put \"" << books[i].second.first
									<< "\" after \""
									<< books[j].second.first << "\""
									<< endl;
							books[i].second.second = -1;
							flag = 0;
							break;
						}
					}
					if (flag) {
						cout << "Put \"" << books[i].second.first << "\" first"
								<< endl;
						books[i].second.second = -1;
					}
				}
			}
			cout << "END\n";
		} else {
			break;
		}
	}
	return 0;

}
