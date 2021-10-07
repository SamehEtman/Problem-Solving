#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
vector<vector<int>> adjList;
vector<bool> visited ;

int main() {
    int N; // number of nodes

    queue <int> q;
    vector<int> p (N , intMax);
    q.push(0);
    p[0] = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop ();
        for (int i = 0 ;i < adjList[u].size() ; i++){
            int v = adjList[u][i];
            if (p[v] == intMax){
                q.push(v);
                p[v] = p[u] + 1;
            }
        }
    }    

}