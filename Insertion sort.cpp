#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
using namespace std;

// Function to perform insertion sort.
void insertionsort(int a[], int n)
{
    // Iterate  the array from the second element.
    for (int i = 1; i < n; i++)
    {
        // Store the current element.
        int key = a[i];
        // Initialize j as the previous index.
        int j = i - 1;
        // Move elements of a[0..i-1], that are greater than key.
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        // Insert the key into its correct position.
        a[j + 1] = key;
    }
}

void puzzleout()
{

    int n;
    // Read the size of the array.
    cin >> n;
    // Initialize the array.
    int a[n];
    // Read the elements of the array.
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // Sort the arry using insertion sort.
    insertionsort(a, n);
    // Print the sorted array.
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
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