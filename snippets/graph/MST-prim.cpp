#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647

int V, E;

vector<vector<pair<int, int>>> adjList;
vector<int> tp;
vector<bool> visited;
priority_queue<pair<int , int>> pq;

void process (int u){
    visited[u] = 1;
    for (int j = 0 ;j < adjList[u].size() ; j++){
        pair<int, int> v = adjList[u][j];
        if (!visited[v.first]){
            pq.push(make_pair(-v.second , -v.first));
        }
    }
}

void prim (){
    process(0);
    int mst_cost = 0;
    while(!pq.empty()){
        pair<int, int> u = pq.top();
        pq.pop();
        if (!visited[u.first]){
            mst_cost += -u.second;
            process(-u.first);
        }
    }
}
int main()
{   
    
    return 0;
}