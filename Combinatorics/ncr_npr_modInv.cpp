/// Author: Mazed Hossain Parag (mhparag25@gmail.com)


/// tasted in lightOj-1067   -> https://lightoj.com/problem/combinations
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

// n! = 1 * 2 * 3 * ...... * n
const int nmax = 1e6;
const int mod = 1000003;
ll fact[nmax+5];

ll bin_expo(int a, int b){ // it will return a^b
    if(b==0) return 1%mod;
    ll x = bin_expo(a, b/2);
    if(b&1){
        return (((x*x)%mod)*a)%mod;
    }
    else{
        return (x*x)%mod;
    }
}

ll mod_inv(int n){
    return bin_expo(n, mod-2)%mod;
}

ll ncr(int n, int r){ // n! / (r!*(n-r)!)
    ll a = fact[n];
    ll b = (fact[r]*fact[n-r])%mod;
    return (a*mod_inv(b))%mod;
}

ll npr(int n, int r){ // n! / (n-r)!
    ll a = fact[n];
    ll b = (fact[n-r])%mod;
    return (a*mod_inv(b))%mod;
}

void sovle(int tc){
    int n,r; cin>>n>>r;
    cout<<"Case "<<tc<<": ";
    cout<<ncr(n,r)<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);

    // precal for 1 to nmax factorial
    fact[0] = 1;
    for(ll i=1; i<=nmax; i++){
        fact[i] = (fact[i-1] * i)%mod;
    }

    int t; cin>>t;
    for(int i=1; i<=t; i++){
        sovle(i);
    }

    return 0;
}
