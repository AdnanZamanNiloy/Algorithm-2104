#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second<b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    // Sort v based on finish time
    sort(v.begin(), v.end(), compare);

    int count = 1; // first activity is always selected
    int last_finish = v[0].second;
    vector<pair<int,int>>ans;
    ans.push_back({v[0].first,v[0].second});
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= last_finish)
        {
            ans.push_back({v[i].first,v[i].second});
            last_finish = v[i].second;
            count++;

        }
    }
    cout << "Maximum number of activities that can be performed is " << count << "\n";
    cout << "Activities are: \n";
    for(auto x:ans)
    {
        cout<<x.first<<" "<<x.second<<"\n";
    }
    return 0;
}