#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <bitset>
#include <limits>
#include <set>
using namespace std;
#define MAX 1000100

int main()
{
   int n ,m ;
   while (cin >> n >>m &&( n || m)){
	   bool end = false;
	   bitset<MAX> set0;
	   set0.reset();
	   while (n--){
		   int a , b;
		   cin >> a >>b;
		   for (int i = a;i <b && !end;i++){
			   if (set0.test(i)){
				   cout << "CONFLICT\n";
				   end = true;
				   break;
			   }
			   set0.set(i, 1);
		   }
	   }
	   while (m--){
		   int a , b , interval;
		   cin >> a >> b >>interval;
		   while (a < 1000000  && !end){
			   for (int i = a ;i <min(b,1000000) && !end;i++){
				   if (set0.test(i) ){
					   cout << "CONFLICT\n";
					   end = true;
					   break;
				   }
				   set0.set(i, 1);
			   }
			   a+=interval; b+=interval ;
		   }
	   }
	   if (!end)cout << "NO CONFLICT\n";
   }
    return 0;
}
