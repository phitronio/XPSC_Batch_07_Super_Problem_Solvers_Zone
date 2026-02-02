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

const int nmax = 2e5+5;
vector<int> adj[nmax];
int cnt[nmax];
set<int> par[nmax];
int mx = 0;

void dfs(int u, int p, int d){
    mx = max(mx, d);
    cnt[d]++;
    if(p!=-1) par[d].insert(p);
    for(int v : adj[u]){
        if(v==p) continue;
        dfs(v, u, d+1);
    }
}

void solve(int test_case){
    int n; cin>>n;
    for(int i=0; i<=n; i++){
        adj[i].clear();
        cnt[i] = 0;
        par[i].clear();
    }
    mx = 0;
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1, 1);
    int ans = 0;
    for(int i=1; i<=mx; i++){
        int st = cnt[i];
        if(sz(par[i])==1) st++;
        ans = max(ans, st);
    }
    cout<<ans<<nl;
}   

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
