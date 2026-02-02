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

const int oo = 1e9+5;

void solve(int test_case){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> w = v;
    sort(all(w));
    int mx = w.back(), mn = w[0];
    int ans = 0;
    int lo=0, hi=oo;
    while(lo<=hi){
        int k = (lo+hi)/2;
        int flag = true;
        for(int i=0; i<n; i++){
            int x = v[i];
            if(x==w[i]) continue;
            if( !(mx-x >= k || x-mn >=k) ) {
                flag = false;
                break;
            }
        }
        if(flag){
            ans = max(ans, k);
            lo = k+1;
        }
        else{
            hi = k-1;
        }
    }
    if(ans==oo) cout<<-1<<nl;
    else cout<<ans<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
