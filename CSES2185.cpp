// USER: "Ab.Mahin"
// Problem: Prime Multiples
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2185
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
const ll N = 1e7 + 5;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll n, k;
    cin >> n >> k;
    
    ll a[k];
    
    for(ll i = 0; i < k; i++) cin >> a[i];
    
    ll ans = 0;
    
    for(ll i = 1; i < (1 << k); i++){
    	ll c = 0, val = 1;
    	for(ll j = 0; j < k; j++){
    		if(i & (1 << j)){
    			c++;
    			if(val > (n / a[j])){
    				val = n + 1;
    			}
    			else val *= a[j];
    		}
    	}
    	if(c & 1) ans += (n / val);
    	else ans -= (n / val);
    }
    cout << ans << '\n';
    
    
    return 0;
}