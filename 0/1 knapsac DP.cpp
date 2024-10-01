#include <bits/stdc++.h>
using namespace std;

int knapsack(int w, int weights[], int values[], int n)
{
    int dp[n + 1][w + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
        for(int j=0;j<=w;j++)
        {
            if(weights[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i-1]]+values[i-1]);
            }
        }
    }

    return dp[n][w];
}

int main()
{
    int n, w;
    cin >> n >> w;
    int weights[n], values[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    cout << "Maximum value in knapsack = " << knapsack(w, weights, values, n) << endl;
    return 0;
}
