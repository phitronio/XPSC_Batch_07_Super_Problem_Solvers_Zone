//Problem: C. Password Cracking
// Problem Link: https://codeforces.com/contest/2013/problem/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int query(deque<char> &s)
{
    cout << "? ";
    for(auto u: s)
        cout << u;
    cout << endl;
    int x;
    cin >> x;
    return x;
}
 
void answer(deque<char> &s)
{
    cout << "! ";
    for(auto u: s)
        cout << u;
    cout << endl;
}
 
void solve()
{
    int n;
    cin >> n;
    deque<char> s;
    while(s.size() < n)
    {
        s.push_back('0');
        if(query(s))
            continue;
 
        s.back() = '1';
 
        if(query(s))
            continue;
        else
        {
            s.pop_back();
            break;
        }
    }
    
    while(s.size() < n)
    {
        s.push_front('0');
        if(query(s))
            continue;
        else
            s.front() = '1';
    }
 
    answer(s);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
 
 
    return 0;
}