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
    string s; cin>>s;
    string t = s;
    sort(all(t));
    if(s==t){
    	cout<<"Bob"<<nl;
    	return;
    }
    vector<int> idx;
    for(int i=0; i<n; i++){
    	if(s[i]!=t[i]){
    		idx.push_back(i);
    	}
    }
    for(int i=1; i<sz(idx); i++){
    	if(s[idx[i]]>s[idx[i-1]]){
    		cout<<"Bob"<<nl;
    		return;
    	}
    }
    cout<<"Alice"<<nl;
    cout<<sz(idx)<<nl;
    for(int x : idx){
    	cout<<x+1<<sp;
    }
    cout<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
