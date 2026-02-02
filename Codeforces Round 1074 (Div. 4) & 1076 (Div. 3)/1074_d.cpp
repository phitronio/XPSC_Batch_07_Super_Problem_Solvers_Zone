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
    int n,m,h; cin>>n>>m>>h;
    vector<int> a(n+1), dif(n+1, 0), upd(n+1, -1);
    for(int i=1; i<=n; i++) cin>>a[i];
    int last = -1;
    for(int i=1; i<=m; i++){
        int b, c; cin>>b>>c;
        if(upd[b] < last){
            dif[b] = 0;
        }
        dif[b] += c;
        upd[b] = i;
        if(a[b] + dif[b] > h){
            last = i;
            dif[b] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        if(upd[i] < last){
            dif[i] = 0;
        }
        cout<<a[i] + dif[i]<<sp;
    }
    cout<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
