// USER: "Ab.Mahin"
// Problem: E. Klever Permutation
// Contest: Codeforces - Codeforces Round 923 (Div. 3)
// URL: https://codeforces.com/contest/1927/problem/E
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
        ll ans[n + 1];
        ll d = 0;
        for(ll i = 1; i <= k; i++){
        	ll c = 0;
        	for(ll j = i; j <= n; j += k){
        		if(i & 1){
        			if(j <= n) ans[j] = ++d; 
        		}
        		else{
        			if(j <= n) c++;
        		}
        	}
        	if(i % 2 == 0){
        		d += c;
        		ll x = d;
        		for(ll j = i; j <= n; j += k){
	        		if(j <= n) ans[j] = d--; 
	        	}
	        	d = x;
        	}
        }
        
       	for(ll i = 1; i <= n; i++){
        	cout << ans[i] << ' ';
        }
        cout << '\n';
        
    }
    
    
    return 0;
}