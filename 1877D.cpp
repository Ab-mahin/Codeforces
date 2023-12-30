// USER: "Ab.Mahin"
// Problem: D. Effects of Anti Pimples
// Contest: Codeforces - Codeforces Round 902 (Div. 2, based on COMPFEST 15 - Final Round)
// URL: https://codeforces.com/contest/1877/problem/D
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
#define m 998244353

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

    ll n;
    cin >> n;
    
    ll mx[n + 5]{0}, a[n + 5], pow[n + 1];
    pow[0] = 1;
    for(ll i = 1; i <= n; i++) cin >> a[i], pow[i] = (pow[i - 1] * 2) % m;
    
    for(ll i = 1; i <= n; i++){
    	for(ll j = i; j <= n; j += i){
    		mx[i] = max(mx[i], a[j]); 
    	}
    }
        
    sort(mx + 1, mx + n + 1, greater<ll>());    
    ll ans = 0;
    
    for(ll i = 1; i <= n; i++){
    	ans = (ans + (mx[i] * pow[n - i]) % m) % m;
    }
    
    cout << ans << '\n';
        
    return 0;
}