#include<bits/stdc++.h>
using namespace std;
const int N = 100;
vector<int> fib(N);

int fibonacci(int n)
{
    if (n <= 1)
        return n;    
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<=n;i++)
    {
       fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n];
}

int main()
{
    int n;
    cin >> n;
    cout <<fibonacci(n) << endl;
    return 0;
}
