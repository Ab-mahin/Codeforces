// USER: "Ab.Mahin"
// Problem: E. Iva & Pav
// Contest: Codeforces - Codeforces Round 900 (Div. 3)
// URL: https://codeforces.com/contest/1878/problem/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
        ll n;
        cin >> n;
        ll a[n + 1];
        vector<ll> v[31];
        
        for(ll i = 0; i < 31; i++) v[i].push_back(0);
        
        for(ll i = 1; i <= n; i++){
        	cin >> a[i];
        	for(ll j = 0; j < 31; j++){
        		if(a[i] & (1 << j)){
        			// hihi
        		}
        		else v[j].push_back(i);
        	}
        }
        for(ll i = 0; i < 31; i++) v[i].push_back(n + 1);
        
        ll q;
        cin >> q;
        
        while(q--){
        	ll l, k;
        	cin >> l >> k;
        	
        	ll r = n;
        	ll id[31]{0};
        	for(ll j = 0; j < 31; j++){
        		ll p = lower_bound(v[j].begin(), v[j].end(), l) - v[j].begin();
    			ll xx = v[j][p];
    			if(xx != l) xx--;
    			id[j] = xx;
        	}
        	
        	for(ll j = 0; j < 31; j++){
        		if(k & (1 << j)){
        			r = min(r, id[j]);
        		}
        		else r = max(r, id[j]);
        	}
        	
        	for(ll i = 0; i < 31; i++){
        		cout << id[i] << ' ';
        	}
        	cout << '\n';
        	
        	if(a[l] < k) r = -1;
        	cout << r << '\n';
        }
        
    }
    
    
    return 0;
}