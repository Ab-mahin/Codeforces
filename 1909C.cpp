// USER: "Ab.Mahin"
// Problem: C. Heavy Intervals
// Contest: Codeforces - Pinely Round 3 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1909/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
//#define m 1000000007 // 998244353
#define MAX LLONG_MAX

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

    ll t, tt;
    t = tt = 1;
    
    cin >> t;
	
    while(t--){
        ll n;
        cin >> n;
        
        vector<ll> a(n), b(n), c(n);
        
        multiset<ll> s;
        
        for(ll i = 0; i < n; i++) cin >> a[i];
        for(ll i = 0; i < n; i++) cin >> b[i], s.insert(b[i]);
        for(ll i = 0; i < n; i++) cin >> c[i];
        
        sort(a.begin(), a.end());
        sort(c.begin(), c.end());
        sort(b.begin(), b.end());
        
        ll ans = 0;
        vector<ll> v;
        
        
        
        for(ll i = n - 1; i >= 0; i--){
        	auto it = s.lower_bound(a[i]);
        	ll x = *it;
        	v.push_back(x - a[i]);
        	s.erase(it);
        }
        
        sort(v.begin(), v.end());
        
        for(ll i = 0; i < n; i++){
        	ans += (v[i] * c[n - i - 1]);
        }
        cout << ans << '\n';
                
    }
    
    
    return 0;
}