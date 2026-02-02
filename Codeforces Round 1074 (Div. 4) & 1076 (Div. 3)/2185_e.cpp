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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> r(n), s(m);
    for(int i=0; i<n; i++) cin>>r[i];
    for(int i=0; i<m; i++) cin>>s[i];
    sort(all(s));
    string ss; cin>>ss;
    priority_queue< pii, vector<pii>, greater<pii> > right;
    priority_queue<pii> left;
    for(int i=0; i<n; i++){
        auto it = lower_bound(all(s), r[i]);
        if(it != s.end()){
            int idx = *it;
            right.push({idx - r[i], i});
        }
        if(it != s.begin()){
            it--;
            int idx = *it;
            left.push({idx - r[i], i});
        }
    }
    int x = 0;
    set<int> dead;
    for(char c : ss){
        if(c=='L') x--;
        else x++;
        while(!right.empty()){
            auto[a, b] = right.top();
            if(a > x){
                break;
            }
            right.pop();
            dead.insert(b);
        }
        while(!left.empty()){
            auto[a, b] = left.top();
            if(a < x) break;
            left.pop();
            dead.insert(b);
        }
        cout<<n - sz(dead)<<sp;
    }
    cout<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
 
