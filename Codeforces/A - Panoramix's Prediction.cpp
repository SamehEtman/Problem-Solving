#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>
#include <iomanip>
using namespace std;
int is_prime(int n)
{
  bool flag = false;
  for(int i = 2; i <= n/2; ++i)
  {
      if(n%i == 0)
      {
          flag = true;
          break;
      }
  }
  return flag;
}
int main() {
	int n, m;
	cin >> n >> m;
	int ans;
	for (int i = n+1 ; i <=50 ; i++){
		if (!is_prime(i)){
			ans = i;
			break;
		}
	}
	if (ans == m) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}