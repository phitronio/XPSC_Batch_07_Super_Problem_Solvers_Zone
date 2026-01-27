// Problem: E. Klee's SUPER DUPER LARGE Array
// Problem Link: https://codeforces.com/problemset/problem/2009/E

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k;

ll sum(ll f, ll s)
{
    if (f == s)
        return f;
    return ((f + s) * (s - f + 1)) / 2LL;
}

bool good(ll m)
{
    if (sum(k, m) <= sum(m + 1, k + n - 1))
        return true;
    else
        return false;
}

bool good2(ll m)
{
    if (sum(k, m - 1) >= sum(m, k + n - 1))
        return true;
    else
        return false;
}

void solve(ll tttt)
{
    cin >> n >> k;
    ll l = k;
    ll r = k + n;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (good(m))
            l = m;
        else
            r = m;
    }

    ll l2 = k, r2 = k + n;
    while (l2 + 1 < r2)
    {
        ll m = (l2 + r2) / 2;

        if (good2(m))
            r2 = m;
        else
            l2 = m;
    }

    cout << min(sum(l + 1, n + k - 1) - sum(k, l), sum(k, r2 - 1) - sum(r2, n + k - 1)) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++)
    {
        solve(tt);
    }
    return 0;
}