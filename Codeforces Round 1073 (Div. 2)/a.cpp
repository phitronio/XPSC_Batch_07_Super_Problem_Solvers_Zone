/// Author: Mazed Hossain Parag (mhparag25@gmail.com)


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define nl "\n"
#define sp " "
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define pii pair<int,int>

bool okay(vector<int> &v, vector<int> &mp, int n){
	for(int i=1; i<n; i++){
		if(mp[v[i]]==mp[v[i-1]]){
			return false;
		}
	}
	return true;
}

void solve(int test_case){
	int n; cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	vector<int> mp(n+1);
	for(int i=1, j=0; i<=n; i++, j^=1){
		mp[i] = j;
	}   
	if(okay(v, mp, n)){
		cout<<"YES"<<nl;
		return;
	}
	for(int i=1, j=1; i<=n; i++, j^=1){
		mp[i] = j;
	}   
	if(okay(v, mp, n)){
		cout<<"YES"<<nl;
		return;
	}
	cout<<"NO"<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(nullptr);cin.tie(nullptr);
    int t; cin>>t;
    for(int tc=1; tc<=t; tc++) solve(tc);
    return 0;
}
 
