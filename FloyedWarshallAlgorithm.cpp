#include <bits/stdc++.h>
using namespace std;
#define INF 1000000
const int N = 100;
int dist[N][N];

void FloydWarshall(int v)
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

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        dist[x][y] = w;
    }

    FloydWarshall(v);

    return 0;
}
