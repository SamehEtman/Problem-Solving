#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
#define LSOne(S) (S & (-S))
#define ii pair<int, int>

const int mod = 1e9 + 7;
vector<vector<ii>> adjList;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for (int z = 1; z <= tc; z++) {
        int N, M, s, t;
        cin >> N >> M >> s >> t;
        adjList.assign(N, vector<ii>());
        for (int i = 0; i < M; i++) {
            int source, dist, cost;
            cin >> source >> dist >> cost;
            adjList[source].push_back({dist, cost});
            adjList[dist].push_back({source, cost});
        }

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        vector<int> dist(N, intMax);
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            ii p = pq.top();
            pq.pop();
            int u = p.second;
            int d = p.first;
            if (d > dist[u])
                continue;
            for (int i = 0; i < adjList[u].size(); i++) {
                ii v = adjList[u][i];
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
        cout << "Case #" << z << ": ";
        if (dist[t] == intMax)
            cout << "unreachable\n";
        else
            cout << dist[t] << endl;
    }
}