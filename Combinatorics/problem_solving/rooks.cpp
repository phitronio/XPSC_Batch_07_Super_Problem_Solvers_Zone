/// Author: Mazed Hossain Parag (mhparag25@gmail.com)
/// rooks -> https://lightoj.com/problem/rooks
#ifdef DeBuG
#include "debug.h"
#else
#include <bits/stdc++.h>
#define dbg(...)
#endif

using namespace std;
typedef long long int ll;
#define nl "\n"
#define sp " "
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define pii pair<int,int>

ll ncr(ll n, ll r){
    if(r > n) return 0;
    ll ans = 1;
    for(ll i=0; i<r; i++){
        ans = ans * (n-i) / (i+1);
    }
    return ans;
}

void solve(int tc){
    ll n,k; cin>>n>>k;
    /// ans = nCk * nCk * k!
    ll kfact = 1;
    for(int i=1; i<=k; i++){
        kfact*=i;
    }
    cout<<"Case "<<tc<<": "<<ncr(n, k)*ncr(n, k)*kfact<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);

    int t; cin>>t;
    for(int i=1; i<=t; i++){
        solve(i);
    }

    return 0;
}
