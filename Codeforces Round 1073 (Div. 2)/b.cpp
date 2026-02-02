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
	vector<int> v(n), suf(n), pre(n);
	for(int i=0; i<n; i++) cin>>v[i];
	set<int> st;
	for(int i=0; i<=n; i++) st.insert(i);
	sort(all(v));
	for(int i=0; i<n; i++){
		if(st.find(v[i])!=st.end()){
			st.erase(v[i]);
		}
		int mex = *st.begin();
		pre[i] = mex;
	}
    st.clear();
    for(int i=0; i<=n; i++) st.insert(i);
	for(int i=n-1; i>=0; i--){
		if(st.find(v[i])!=st.end()){
			st.erase(v[i]);
		}
		int mex = *st.begin();
		suf[i] = mex;
	}
	for(int i=0; i<n-1; i++){
		if(pre[i]==suf[i+1]){
			cout<<"NO"<<nl;
			return;
		}
	}
	cout<<"YES"<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
