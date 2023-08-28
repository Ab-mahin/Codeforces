// USER: "Ab.Mahin"
// Problem: C. Division and Union
// Contest: Codeforces - Educational Codeforces Round 58 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1101/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define m 1000000007


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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        
        vector<pair<pair<ll ,ll>, ll>> v;
        ll ok = 0;
        ll ans[n];
        
        for(ll i = 0; i < n; i++){
        	ll l, r;
        	cin >> l >> r;
        	v.push_back({{l, r}, i});
        }
        
        sort(v.begin(), v.end());
        
        ll x = 0;
        for(ll i = 0; i < n - 1; i++){
        	x = max(x, v[i].first.second);
        	ll y = v[i + 1].first.first;
        	
        	if(ok) ans[v[i].second] = 2;
        	else ans[v[i].second] = 1;
        	if(y > x){
        		ok = 1;
        	}
        }
        
        
        if(ok){
        	ans[v[n - 1].second] = 2;
        	for(auto i : ans){
        		cout << i << ' ';
        	}
        	cout << '\n';
        }
        else cout << -1 << '\n';
        
    }
    
    
    return 0;
}