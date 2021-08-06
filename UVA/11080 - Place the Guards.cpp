#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define intMax 2147483647

int tc, N, E;
vector<vector<int>> adjList;

int main()
{
    cin >> tc;
    while (tc--)
    {
        cin >> N >> E;
        adjList.clear();
        adjList.assign(N, vector<int>());
        for (int i = 0; i < E; i++)
        {
            int a, b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        queue<int> q;
        vector<int> d(N, intMax);
        bool isBibtrate = true;
        int total = 0;
        for (int i = 0; i < N; i++)
        {
            if (d[i] == intMax)
            {
                int arr[2] = {};
                d[i] = 0;
                arr[0]++;
                q.push(i);
                while (isBibtrate && !q.empty())
                {
                    int u = q.front();
                    q.pop();
                    //cout << u << " ----> \n" ;
                    for (int j = 0; j < adjList[u].size(); j++)
                    {
                        int v = adjList[u][j];
                        //cout << v << ' ' << d[v] << endl;
                        if (d[v] == intMax)
                        {
                            d[v] = 1 - d[u];
                            arr[d[v]]++;
                            q.push(v);
                        }
                        else if (d[v] == d[u])
                        {
                            isBibtrate = false;
                            break;
                        }
                    }
                }
                total += max(1, min(arr[0], arr[1]));
            }
        }
        /*cout << endl;
        for (int i = 0; i< N ;i ++){
            cout << i << " " << d[i] <<endl;
        }*/
        if (!isBibtrate)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << total << endl;
        }
    }

    return 0;
}