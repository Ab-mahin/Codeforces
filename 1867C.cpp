// USER: "Ab.Mahin"
// Problem: C. Salyg1n and the MEX Game
// Contest: Codeforces - Codeforces Round 897 (Div. 2)
// URL: https://codeforces.com/contest/1867/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007


template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cout.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 2e5 + 5;


int main(){

        
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    cin >> t;
	read:
    while(t--){
        ll n;
        cin >> n;
        
        set<ll> s;
        vector<ll> v(n);
        for(ll i = 0; i < n; i++){
        	cin >> v[i];
        	s.insert(v[i]);
        }
        
        sort(v.begin(), v.end());   
        
        
        ll xx = 0, val;
        auto it = s.begin();
        while(xx < s.size() && xx == *it){
        	xx++;
        	it++;
        }
        
        again:
        cout << xx << endl;
        cin >> val;
        xx = val;
        if(val == -1) goto read;
        goto again;
        
    }
    
    
    return 0;
}