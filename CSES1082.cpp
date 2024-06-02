// USER: "Ab.Mahin"
// Problem: Sum of Divisors
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1082/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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
const ll N = 2e6 + 5;
bitset<N> pr;
vector<ll> v;
 
ll bigmod(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return (b * bigmod(b, p - 1)) % m;
	ll x = bigmod(b, p / 2);
	return (x * x) % m;
}
 
ll fun(ll n){
	n %= m;
	return (n * (n + 1) % m) * bigmod(2, m - 2) % m;
}
ll val(ll n, ll x){
	return (fun(n) - fun(x) + m) % m;
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
	
	//siv();
	
    while(t--){
        ll n;
        cin >> n;
        
        ll ans = 0;
        ll p = n;
        for(ll i = 1; i <= round(sqrt(n + 1)); i++){
        	ll x = (n / i);
        	ans = (ans + (i * x) % m) % m;
        	if(x == (i - 1)) ans = (ans - ((x * i) % m) + m) % m;
        	if(x == 1) break;
        	ans = (ans + (val(p, x)) * (i - 1) % m) % m;
        	p = x;
        }
        
        cout << ans << '\n';
       	    
    }
    
    
    return 0;
}