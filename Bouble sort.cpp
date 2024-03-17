#include <bits/stdc++.h>
using namespace std;

void boubleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void puzzleout()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    boubleSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
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