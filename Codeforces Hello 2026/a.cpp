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
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    if(v[0]==0 && v.back()==0) cout<<"Bob"<<nl;
    else cout<<"Alice"<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
