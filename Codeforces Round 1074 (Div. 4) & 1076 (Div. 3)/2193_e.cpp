/// Author: Mazed Hossain Parag (mhparag25@gmail.com)

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

const int nmax = 3e5;
int taw[nmax+10];
vector<int>divisors[nmax+10];
const int oo = 1e9;

/// complexity o(n lon(n))
void seiveTaw(){
    for(int i=1; i<=nmax; i++){
        for(int m=i; m<=nmax; m+=i){
            taw[m]++;
            divisors[m].push_back(i);
        }
    }
}

void solve(int test_case){
    int n; cin>>n;
    vector<int> a(n+1), dp(n+1, oo);
    for(int i=1; i<=n; i++){
        cin>>a[i];
        dp[a[i]] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int d : divisors[i]){
            dp[i] = min(dp[i], dp[d] + dp[i/d]);
        }
    }
    for(int i=1; i<=n; i++){
        if(dp[i]>=oo) cout<<-1<<sp;
        else cout<<dp[i]<<sp;
    }
    cout<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    seiveTaw();
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
