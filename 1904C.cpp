// USER: "Ab.Mahin"
// Problem: C. Array Game
// Contest: Codeforces - Codeforces Round 914 (Div. 2)
// URL: https://codeforces.com/contest/1904/problem/C
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
        ll n, k;
        cin >> n >> k;
        ll a[n];
        ll c = 0, ans = MAX;
        
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        }
        sort(a, a  + n);
        
        for(ll i = 0; i < n; i++){
        	ans = min({ans, a[i], i ? abs(a[i] - a[i - 1]) : a[i]});
        }
        if(k == 1){
        	cout << ans << '\n';
        	continue;
        }
        else{
        	for(ll i = 0; i < n; i++){
        		for(ll j = i + 1; j < n; j++){
        			ll x = abs(a[j] - a[i]);
	        		ll p = lower_bound(a, a + n, x) - a;
	        		if(p != 0) ans = min({ans, abs(a[p - 1] - x)});
	        		if(p < n - 1) ans = min({ans, abs(a[p + 1] - x)});
	        		if(p != n) ans = min({ans, abs(a[p] - x)});
        		}
        	}
        }
        if(k >= 3) ans = 0;
        
        cout << ans << '\n';
        
        
                
    }
    
    
    return 0;
}