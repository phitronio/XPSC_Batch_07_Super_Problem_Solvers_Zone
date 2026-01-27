// Problem: F_Final_Boss
// Problem Link: https://codeforces.com/contest/1685/problem/F

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fx[] = {0, 0, 1, -1, 1, 1, -1, -1};
ll fy[] = {1, -1, 0, 0, -1, 1, -1, 1};

bool good(ll m, ll n, ll h, vector<ll> &a, vector<ll> &c)
{
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = min(cnt + (1 + (m - 1) / c[i]) * a[i], h);
    }

    return cnt == h;
}

void solve(int tt)
{
    ll n, h;
    cin >> h >> n;
    vector<ll> a(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    ll l = 0, r = 1e12;
    while (l + 1 < r)
    {
        ll m = (l + r) / 2;
        if (good(m, n, h, a, c))
            r = m;
        else
            l = m;
    }
    cout << r << "\n";
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