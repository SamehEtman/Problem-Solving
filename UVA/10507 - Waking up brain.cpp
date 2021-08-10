#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647
#define vi vector<int>
int N, E;
vector<vector<int>> adjList;
vector<bool> visited;
int main()
{
    while (cin >> N >> E)
    {

        adjList.assign(N, vector<int>());
        visited.assign(N, 0);
        int idx = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < 3; i++)
        {
            char c;
            cin >> c;
            mp[c] = idx++;
            visited[mp[c]] = 1;
        }
        for (int i = 0; i < E; i++)
        {
            char a, b;
            cin >> a >> b;
            if (mp.find(a) == mp.end())
                mp[a] = idx++;
            if (mp.find(b) == mp.end())
                mp[b] = idx++;

            adjList[mp[a]].push_back(mp[b]);
            adjList[mp[b]].push_back(mp[a]);
        }

        int count = 3, // count the visited nodes which is set to 3 by default
            ans = 0;
        bool flag = 1;

        while (count < N)
        {
            vector<int> wakeUp;

            for (int i = 0; i < N; i++)
            {
                // count awake connected to each unvisited node
                // if they are 3 or more push it back to our wakeUp vector
                if (!visited[i])
                {
                    int upNeighboursCount = 0;
                    vector<int> neighbours = adjList[i];
                    for (int i = 0; i < neighbours.size(); i++)
                    {
                        if (visited[neighbours[i]])
                            upNeighboursCount++;
                    }
                    if (upNeighboursCount >= 3)
                    {
                        wakeUp.push_back(i);
                    }
                }
            }
            // if no node is connected to 3 awake nodes
            if (wakeUp.size() == 0)
            {
                flag = 0;
                break;
            }
            count += wakeUp.size();

            // mark the waken nodes as visited
            for (int i = 0; i < wakeUp.size(); i++)
                visited[wakeUp[i]] = 1;
            ans++;
        }
        if (flag)
            printf("WAKE UP IN, %d, YEARS\n", ans);
        else
            printf("THIS BRAIN NEVER WAKES UP\n");
    }

    return 0;
}
