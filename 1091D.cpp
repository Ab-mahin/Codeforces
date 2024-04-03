// USER: "Ab.Mahin"
// Problem: D. New Year and the Permutation Concatenation
// Contest: Codeforces - Good Bye 2018
// URL: https://codeforces.com/contest/1091/problem/D
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
//0x3f

#define MAX LLONG_MAX

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//find_by_order() and order_of_key()
//k-th largest element and strictly smaller

//Findout buggs:

#define BUG

#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');
cerr.write(names, comma - names) << " : " << arg1<< " | ";__f(comma+1, args...);
}
#else
#define bug(...)
#endif

//...................
const ll N = 1e6 + 5;
ll fac[N], ifac[N];
ll bigmod(ll a, ll b){
	if(b == 0) return 1;
	if(b & 1) return (a * bigmod(a, b - 1)) % m;
	ll x = bigmod(a, b / 2);
	return (x * x) % m;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
    
    //cin >> t;
    
    fac[0] = ifac[0] = 1;
    
    for(ll i = 1; i < N; i++){
    	fac[i] = (fac[i - 1] * i) % m;
    	ifac[i] = bigmod(fac[i], m - 2);
    }
	
    while(t--){
    	ll n;
        cin >> n;
        ll ans = n * fac[n] % m;
        
        for(ll i = 1; i < n; i++){
        	ans = (ans - (fac[n] * ifac[i]) % m + m) % m;
        }
        
        cout << ans << '\n';
                
    }
    
    
    return 0;
}