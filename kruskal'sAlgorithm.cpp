#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int find(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u], parent);
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int cost = 0;
    vector<pair<int, int>> mst;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (auto it : edges)
    {
        int u = it.second.first;
        int v = it.second.second;
        int w = it.first;
        int x = find(u, parent);
        int y = find(v, parent);
        if (x != y)
        {
            cost += w;
            mst.push_back({u, v});
            parent[x] = y;
        }
    }
    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << " " << it.second << endl;
    return 0;

}
