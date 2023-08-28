// USER: "Ab.Mahin"
// Problem: C. Binary Strings are Fun
// Contest: Codeforces - Codeforces Round 838 (Div. 2)
// URL: https://codeforces.com/contest/1762/problem/C
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
#define mod 998244353


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

ll bigmod(ll a, ll b){
	if(!b) return 1;
	if(b & 1){
		return (a * bigmod(a, b - 1)) % mod;
	}
	else{
		ll x = bigmod(a, b / 2) % mod;
		x = (x * x) % mod;
		return x;
	}
}

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
        
        string s;
        cin >> s;
        ll ans = 1;
        
        ll x = 0;
        char c = s[0];
        for(ll i = 1; i < n; i++){
        	if(c == s[i]){
        		x++;
        		ans = (ans + bigmod(2, x)) % mod;
        	}
        	else x = 0, c = s[i], ans = (ans + 1) % mod;
        }
        
        
        cout << ans << '\n';
    }
    
    
    return 0;
}