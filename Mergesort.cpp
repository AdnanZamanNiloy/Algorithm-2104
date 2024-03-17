#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
using namespace std;
#define ll long long

vector<int> merge(vector<int> &firstarray, vector<int> &secondarray)
{
    int fristarraysize = firstarray.size();
    int secondarraysize = secondarray.size();
    vector<int> result(fristarraysize + secondarraysize);
    int i = 0, j = 0, k = 0;
    while (i < fristarraysize && j < secondarraysize)
    {
        if (firstarray[i] < secondarray[j])
        {
            result[k++] = firstarray[i++];
        }
        else
        {
            result[k++] = secondarray[j++];
        }
    }
    while (i < fristarraysize)
    {
        result[k++] = firstarray[i++];
    }
    while (j < secondarraysize)
    {
        result[k++] = secondarray[j++];
    }
    return result;
}

vector<int> devide(vector<int> &array, int n)
{
    if (n == 1)
    {
        return array;
    }
    int mid = n / 2;
    vector<int> firstarray(mid);
    vector<int> secondarray(n - mid);
    for (int i = 0; i < mid; i++)
    {
        firstarray[i] = array[i];
    }
    for (int i = mid; i < n; i++)
    {
        secondarray[i - mid] = array[i];
    }
    devide(firstarray, mid);
    devide(secondarray, n - mid);
    vector<int> result = merge(firstarray, secondarray);
    for (int i = 0; i < n; i++)
    {
        array[i] = result[i];
    }
    return array;
}

void puzzleout()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    v = devide(v, n);
    for (ll i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC = 1;
    // cin >> TC;
    while (TC--)
    {
        puzzleout();
    }
    return 0;
}
