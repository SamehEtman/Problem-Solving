#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
vector<vector<int>> adjList;
vector<bool> visited;

void fillGraph(int N) {
    adjList[0].push_back(2);
    adjList[2].push_back(0);
    adjList[1].push_back(2);
    adjList[2].push_back(1);
    adjList[3].push_back(2);
    adjList[3].push_back(3);
    adjList[0].push_back(4);
    adjList[4].push_back(0);
}

int main() {
    int N = 5;  // number of nodes
    adjList.assign(N, vector<int>());
    fillGraph(N);

    // BFS
    queue<int> q;
    vector<int> p(N, intMax);
    q.push(0);
    p[0] = 0;
    bool isBibtrate = true;
    while (!q.empty() && isBibtrate) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (p[v] == intMax) {
                q.push(v);
                p[v] = 1 - p[u];
            } else if (p[v] == p[u]) {
                isBibtrate = false;
                break;
            }
        }
    }
    cout << isBibtrate << endl;
}