/*Given a value of amount  and an infinite supply of each of the 
denominations arr{..........} of size n valued coins/notes,
The task is to find the minimum number of coins and/or notes needed to 
make the change?*/

#include <bits/stdc++.h>
using namespace std;

void coinChange(vector<int> coins, int amount)
{
    sort(coins.begin(), coins.end(), greater<int>());
    int n = coins.size();
    vector<int> count(n, 0);
    for (int i = 0; i <n; i++)
    {
        count[i] = amount / coins[i];
        amount %= coins[i];
    }
    for (int i = 0; i < coins.size(); i++)
    {
        if (count[i] > 0)
        {
            cout << "Use " << count[i] << " coins of denomination " << coins[i] << "\n";
        }
    }
}

int main()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    coinChange(coins, amount);
    return 0;
}
