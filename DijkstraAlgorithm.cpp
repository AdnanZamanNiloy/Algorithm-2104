#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
const int INF = 1e9;

vector<int> parent(N);
vector<int> dist(N, INF);
vector<pair<int, int>> g[N];

void dijkstra(int source)
{
    vector<int> vis(N, 0);
    set<pair<int, int>> s;

    dist[source] = 0;
    s.insert({0, source});

    while (s.size())
    {
        auto x = *(s.begin());
        int cur_dist = x.first;
        int node = x.second;
        s.erase(x);
        if (vis[node])
            continue;
        vis[node] = 1;
        for (auto child : g[node])
        {
            int childNode = child.first;
            int childDist = child.second;
            if (cur_dist + childDist < dist[childNode])
            {
                parent[childNode] = node;
                dist[childNode] = cur_dist + childDist;
                s.insert({dist[childNode], childNode});
            }
        }
    }
}

void printPath(int i)
{
    if (i == 0)
        return;
    cout << "->";
    cout << parent[i];
    printPath(parent[i]);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << "Node: " << i << "  Cost: " << dist[i] << " Path: ";
        cout << i;
        printPath(i);
        cout << "\n";
    }
}
