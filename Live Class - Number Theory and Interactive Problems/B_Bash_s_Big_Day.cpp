// Problem: B. Bash's Big Day
// Problem link: https://codeforces.com/contest/757/problem/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> prime_divisors(100005);
    for (int i = 2; i < 100005; i++)
    {
        if (prime_divisors[i].empty())
        {
            for (int j = i; j < 100005; j += i)
            {
                prime_divisors[j].push_back(i);
            }
        }
    }
 
    int n;
    cin >> n;
 
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for(auto u: prime_divisors[a[i]])
        {
            freq[u]++;
        }
    }
 
    int mx = 1;
    for(auto [f, s]: freq)
    {
        mx = max(mx, s);
    }
 
    cout << mx << '\n';



    return 0;
}
