// Problem: B. Sherlock and his girlfriend
// Problem Link: https://codeforces.com/problemset/problem/776/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Just call Prime(n) in main function
vector<ll> prime;
bool visprime[1000005];
void Prime(ll NN)
{
    prime.push_back(2);
    for (ll i = 4; i <= NN; i += 2)
        visprime[i] = true;

    for (ll i = 3; i <= NN; i += 2)
    {
        if (visprime[i])
            continue;
        prime.push_back(i);
        for (ll j = i * i; j <= NN; j += (2 * i))
            visprime[j] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    Prime(n + 5);

    if(n <= 2)
    {
        cout << 1 << "\n";
        for(int i = 0; i < n; i++)
            cout << 1 << " ";
        cout << "\n";
    }
    else
    {
        cout << 2 << "\n";
        for(int i = 2; i <= n + 1; i++)
        {
            if(visprime[i])
                cout << 2 << " ";
            else
                cout << 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
