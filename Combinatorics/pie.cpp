/// Author: Mazed Hossain Parag (mhparag25@gmail.com)

#ifdef DeBuG
#include "debug.h"
#else
#include <bits/stdc++.h>
#define dbg(...)
#endif

/// principle of inclusion exclusion -> https://www.spoj.com/problems/NGM2/en/

using namespace std;
typedef long long int ll;
#define nl "\n"
#define sp " "
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define pii pair<int,int>


/// let A = div by x1
/// let B = div by x2
/// ans = n - at least divisible by one of xi
/// ans = n - #(A U B)
/// #(A U B) = #(A) + #(B) - #(A ^ B) ---> PIE
/// #(A ^ B) = n / lcm(A,B)


ll lcm(vector<ll> &v){
    ll ret = v[0];
    for(int i=1; i<sz(v); i++){
        ret = ((v[i]*ret) / __gcd(v[i], ret));
    }
    return ret;
}

ll interset(vector<ll> &v, ll n){
    return n / lcm(v);
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);

    ll n,k; cin>>n>>k;
    vector<ll> x(k);
    for(int i=0; i<k; i++) cin>>x[i];
    ll sub = 0;
    for(ll mask = 1; mask<(1<<k); mask++){
        vector<ll> v;
        for(ll i=0; i<k; i++){
            ll bitmask = (1ll<<i);
            if((bitmask&mask)!=0) v.push_back(x[i]);
        }
        if(sz(v)&1){
            sub += interset(v, n);
        }
        else{
            sub -= interset(v, n);
        }
    }
    cout<< n - sub << nl;
    return 0;
}
