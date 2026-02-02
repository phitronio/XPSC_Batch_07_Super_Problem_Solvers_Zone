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

int n,m,k;

bool okay(int x, int y){
    return max(x,y)-1 + x + y <= m;
}

void solve(int test_case){
    cin>>n>>m>>k;
    int x=0, y=0;
    while(1){
        bool flag = false;
        if(x < k-1){
            if(okay(x+1, y)){
                flag = true;
                x++;
            }           
        }
        if(y < n-k){
            if(okay(x, y+1)){
                flag = true;
                y++;
            }
        }
        if(!flag) break;
    }        
    cout<<x+y+1<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
