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
#include <limits>
#include <set>
using namespace std;
int main()
{
    int n ; cin >> n;
	bool flag_first = false;

    while (n--){
    	if(flag_first){
    		cout<<endl;
		}
    	int B , SG , SB ;
    	cin >> B >> SG >> SB;
    	multiset <int, greater <int> > Sg;
    	multiset <int, greater <int> > Sb;
    	int inp;
    	for (int i = 0 ; i < SG ;i++) {
    		cin >> inp;
    		Sg.insert(inp);
    	}
    	for (int i = 0 ; i < SB ;i++) {
    	    cin >> inp;
    	    Sb.insert(inp);
    	}
    	vector <int> fsg;
    	vector <int> fsb;
    	multiset <int, greater <int> > ::iterator it1 =Sg.begin();
    	multiset <int, greater <int> > ::iterator it2 =Sb.begin();

    	while(!Sg.empty() && !Sb.empty()){
			int actualB = min (B , min ((int)Sg.size() ,(int) Sb.size()));
			int i = 0;
			for (it1 = Sg.begin(); i <actualB;i++){
				fsg.push_back(*it1);
				Sg.erase(it1++);
			}
			i = 0;
			for (it2 = Sb.begin(); i <actualB;i++){
				fsb.push_back(*it2);
				Sb.erase(it2++);
			}
			for (i = 0 ;i < actualB;i++){
				if (fsg[i] >=fsb[i]){
					fsg[i] -= fsb[i];
					fsb[i] = 0;
				}else {
					fsb[i] -=fsg[i];
					fsg[i] =0;
				}
			}
			for (i = 0;i <actualB;i++){
				if (fsb[i]!=0){
					Sb.insert(fsb[i]);
				}
				if (fsg[i]!=0){
					Sg.insert(fsg[i]);
				}
			}
			fsb.clear();
			fsg.clear();
    	}
			if (Sg.size() > Sb.size()){
				cout << "green wins\n";
				for (it1 = Sg.begin() ; it1!=Sg.end();it1++) cout << *it1 <<endl;
			}else if (Sg.size() < Sb.size()) {
				cout << "blue wins\n";
				for (it2 = Sb.begin() ; it2!=Sb.end();it2++) cout << *it2 <<endl;
			}else {
				cout << "green and blue died\n";
			}
			if (n > 0) cout << endl;

    }
    return 0;
}
