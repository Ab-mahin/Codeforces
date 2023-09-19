// USER: "Ab.Mahin"
// Problem: C2. Sheikh (Hard Version)
// Contest: Codeforces - Codeforces Round 830 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1732/C2
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
        ll n, q;
        cin >> n >> q;
        
        vector<ll> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0), pos;
        
        for(ll i = 1; i <= n; i++){
        	cin >> a[i];
        	c[i] = c[i - 1] + a[i];
        	b[i] = b[i - 1] ^ a[i];
        	if(a[i]) pos.push_back(i);
        }
        
        
        while(q--){
        	ll l, r;
        	cin >> l >> r;
        	ll u = l, v = r;
	        ll x = (c[r] - c[l - 1]) - (b[r] ^ b[l - 1]);
	        
	        if(!x) v = l;
	        
	        ll id = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
        	
        	for(ll i = id; i < min(id + 35, (ll)pos.size()); i++){
        		
        		if(pos[i] > r) break;
        	
	        	ll lo = pos[i], hi = r, p = pos[i], q = r;
	        	ll y = (c[r] - c[p - 1]) - (b[r] ^ b[p - 1]);
	        	
	        	if(x != y) break;
	        	
	        	while(lo <= hi){
	        		ll mid = (lo + hi) >> 1;
	        		y = (c[mid] - c[p - 1]) - (b[mid] ^ b[p - 1]);
	        		if(y < x){
	        			lo = mid + 1;
	        		}
	        		else hi = mid - 1, q = mid;
	        	}
	        	
	        	if(q - p + 1 < v - u + 1){
	        		u = p;
	        		v = q;
	        	}
	        }
	        	
        	cout << u << ' ' << v << '\n';        	
        }
        
    }
    
    return 0;
}