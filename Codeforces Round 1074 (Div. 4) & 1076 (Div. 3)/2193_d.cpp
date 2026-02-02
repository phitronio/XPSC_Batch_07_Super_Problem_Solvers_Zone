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

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void solve(int test_case){
    int n; cin>>n;
    vector<ll> a(n), b(n), pre(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    sort(all(a));
    pre[0] = b[0];
    for(int i=1; i<n; i++){
        pre[i] = pre[i-1] + b[i];
    }
    ll ans = 0;
    for(int i=0; i<n; i++){
        ll dif = a[i];
        ll sowrd = n-i;
        ll lo=0, hi=n-1;
        ll x = -1;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            if(pre[mid] <= sowrd){
                x = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        ans = max(ans, dif * (x+1));
    }
    cout<<ans<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
