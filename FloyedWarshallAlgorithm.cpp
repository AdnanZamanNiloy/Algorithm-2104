#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
const int N = 100;

void FloydWarshall(int dist[N][N], int v)
{
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            if (dist[i][j] < 0)
            {
                cout << "Negative cycle found\n";
                return;
            }
    }

    cout << "No negative cycle found\n";
}

int main()
{
    int v, e;
    cin >> v >> e;
    int graph[N][N];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x][y] = w;
    }

    FloydWarshall(graph, v);

    return 0;
}
