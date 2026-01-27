// Problem: C. Insert and Equalize
// Problem Link: https://codeforces.com/contest/1902/problem/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);

    map<int, bool> presence;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        presence[a[i]] = true;
    }

    if(n == 1)
    {
        cout << 1 << "\n";
        return;
    }

    ll gc = 0;
    sort(a.begin(), a.end());
    for(int i = 1; i < n; i++)
    {
        gc = gcd(gc, a[i] - a[0]);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += (a.back() - a[i]) / gc;
    }

    for(ll i = a.back() - gc; 1; i -= gc)
    {
        if(!presence[i])
        {
            ans += (a.back() - i) / gc;
            break;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }


    return 0;
}
