/*Given the weights and profits of N items, in the form of {profit, weight}
 put these items in a knapsack of capacity W to get the maximum total profit
in the knapsack. In Fractional Knapsack, we can break items for maximizing
 the total value of the knapsack.*/

// Time Complexity: O(nlogn)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<pair<int, int>> &v)
{
    sort(v.begin(), v.end(), compare); // Sort the items by value/weight ratio in descending order
    int curWeight = 0;
    double finalprofit = 0.0;

    for (int i = 0; i < v.size(); i++)
    {
        if (curWeight + v[i].second <= W)
        {
            curWeight += v[i].second;
            finalprofit += v[i].first;
        }
        else
        {
            int remain = W - curWeight;
            finalprofit += (v[i].first / v[i].second) * (double)remain;
            break;
        }
    }
    return finalprofit;
}

int main()
{
    int w; //    Weight of knapsack
    cin >> w;
    int n; // Number of items
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    cout << "Maximum value we can obtain = " << fractionalKnapsack(w, v) << endl;
    return 0;
}