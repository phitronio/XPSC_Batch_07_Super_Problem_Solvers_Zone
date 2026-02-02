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
    int n;cin>>n;
    string s; cin>>s;
    vector<pii> v;
    int zero=0, one=0;
    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            if(zero){
                v.push_back({zero, 1 + (one>0)});
            }
            one++;
            zero = 0;
        }
        else{
            zero++;
        }
    }
    if(zero){
        v.push_back({zero, (one>0)});
    }
    int ans = 0;
    for(auto[x, o] : v){
        if(o==0) ans += ((x+2)/3);
        else if(o==1) ans += ((x+1)/3);
        else ans += (x/3);
    }
    cout<<ans+one<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
