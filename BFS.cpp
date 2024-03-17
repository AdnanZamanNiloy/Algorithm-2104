#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
int parent[N];
int level[N];

void bfs(int node)
{
    queue<pair<int, int>> q;
    q.push({node, 0});
    vis[node] = true;
    parent[node] = -1; // root node has no parent
    while (!q.empty())
    {
        int curr = q.front().first;
        int lvl = q.front().second;
        q.pop();
        level[curr] = lvl;
        cout << "Current node: " << curr << ", Level: " << lvl << "\n";
        for (auto i : adj[curr])
        {
            if (!vis[i])
            {
                q.push({i, lvl + 1});
                vis[i] = true;
                parent[i] = curr;
            }
        }
    }
}

void printPath(int node) {
    if(parent[node] == -1) {
        cout << node << " ";
        return;
    }
    printPath(parent[node]);
    cout << node << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);

    for(int i = 1; i <= n; i++) {
        cout << "Shortest path to node " << i << ": ";
        printPath(i);
        cout << "\n";
    }
}