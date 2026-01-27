//Problem: E. Min Max MEX
//Problem Link: https://codeforces.com/problemset/problem/2093/E

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define N 500005

ll fx[] = {0, 0, 1, -1, 1, 1, -1, -1};
ll fy[] = {1, -1, 0, 0, -1, 1, -1, 1};

ll a[N];
ll n, k;

bool good(ll m)
{
    ll cnt = 0;
    ll mex = 0;
    vector<bool>mp(m + 2, 0);
    for(int i = 1; i <= n; i++)
    {
        if(a[i] <= m) mp[a[i]] = 1;
        while(mp[mex])
            mex++;
        if(mex >= m)
        {
            cnt++;
            mp.clear();
            mp.assign(m + 2, 0);
            mex = 0;
        }
    }
    return cnt >= k;
}

void solve(int tt)
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll l = 0, r = n + 2;
    while(l + 1 < r)
    {
        ll m = (l + r) / 2;
        if(good(m)) l = m;
        else r = m;
    }
    cout << l << endl;
}

int main()
{
    FAST;
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++)
    {
        solve(tt);
    }

    return 0;
}