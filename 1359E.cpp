// USER: "Ab.Mahin"
// Problem: E. Modular Stability
// Contest: Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1359/problem/E
// Memory Limit: 512 MB
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
const ll N = 5e5 + 5;
ll fac[N];

ll bigmod(ll a, ll b){
	if(b == 0) return 1;
	if(b & 1){
		return (a * bigmod(a, b - 1) % m) % m;
	}
	else {
		ll x = bigmod(a, b / 2);
		return (x * x) % m;
	}
}

ll nCr(ll n, ll r){
	if(r > n) return 0;
	ll x = fac[n];
	ll y = fac[r];
	ll z = fac[n - r];
	return (x * bigmod(y, m - 2) % m * bigmod(z, m - 2) % m) % m;
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
    
    fac[0] = 1;
    
    for(ll i = 1; i < N; i++){
    	fac[i] = (fac[i - 1] * i) % m;
    }
	
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        for(ll i = 1; i <= n; i++){
        	ans = (ans + nCr((n / i) - 1, k - 1)) % m;
        }
        
        if(k == 1) ans = n;
        
        cout << ans << '\n';
    }
    
    
    return 0;
}