#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m;// n is the number of nodes and m is the number of edges
    cin >> n >> m;
    vector<int> visNodes;
    vector<pair<int, int>> graph[n + 1];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w; // node, node, edge
        graph[u].push_back({v, w});
    }
    vector<int> dist(n + 1, INT_MAX);
    int startNode = 0;
    dist[startNode] = 0;
    visNodes.push_back(startNode);
    int remainingIterations = n - 1;
    while (remainingIterations-- > 0)
    {
        vector<int> newVisNodes;
        for (auto &it : visNodes)
        {
            for (auto &it2 : graph[it])
            {
                if (dist[it2.first] > dist[it] + it2.second)
                {
                    dist[it2.first] = dist[it] + it2.second;
                    newVisNodes.push_back(it2.first);
                }
            }
        }
        visNodes = newVisNodes;
    }
    bool isNegativeCycle = false;
    for (auto &it : visNodes)
    {
        for (auto &it2 : graph[it])
        {
            if (dist[it2.first] > dist[it] + it2.second)
            {
                isNegativeCycle = true;
                break;
            }
        }
    }
    if (isNegativeCycle)
    {
        cout << "Negative Cycle Detected, No Shortest Path\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
