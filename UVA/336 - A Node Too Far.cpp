#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))

const int mod = 1e9 + 7;

int e;
map<int, int> inputToNode;
vector<vector<int>> adjList;
int caseNum;
void solve() {
    inputToNode.clear();

    int node = 1;
    vector<pair<int, int>> edges;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        if (inputToNode.find(a) == inputToNode.end()) {
            inputToNode[a] = node++;
        }
        if (inputToNode.find(b) == inputToNode.end()) {
            inputToNode[b] = node++;
        }
        edges.push_back({inputToNode[a], inputToNode[b]});
    }

    int n = inputToNode.size();

    adjList.assign(n + 1, vector<int>());
    for (int i = 0; i < e; i++) {
        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }

    int z, ttl;
    while (cin >> z >> ttl) {
        if (z == 0 && ttl == 0)
            break;
        int u = inputToNode[z];
        queue<int> q;
        vector<int> dist(n + 1, intMax);
        dist[u] = 0;
        q.push(u);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int j = 0; j < adjList[v].size(); j++) {
                int w = adjList[v][j];
                if (dist[w] == intMax) {
                    dist[w] = dist[v] + 1;
                    q.push(w);
                }
            }
        }
        int numOfNodes = 0;
        for (int i = 1; i <= n; i++)
            if (dist[i] > ttl)
                numOfNodes++;
        cout << "Case " << ++caseNum << ": " << numOfNodes
             << " nodes not reachable from node " << z << " with TTL = " << ttl
             << "." << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int tc = 1;
    // cin >> tc;

    while (cin >> e && e) {
        solve();
    }
}