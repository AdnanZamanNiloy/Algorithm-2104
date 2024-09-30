#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[n1], rightArray[n2];

    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k++] = leftArray[i++];
        }
        else
        {
            array[k++] = rightArray[j++];
        }
    }

    while (i < n1)
    {
        array[k++] = leftArray[i++];
    }
    while (j < n2)
    {
        array[k++] = rightArray[j++];
    }
}

void divide(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        divide(array, left, mid);
        divide(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void puzzleout()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    divide(v, 0, n - 1);
    for (int i = 0; i < n; i++)
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
