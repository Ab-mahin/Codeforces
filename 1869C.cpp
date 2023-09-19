// USER: "Ab.Mahin"
// Problem: C. Fill in the Matrix
// Contest: Codeforces - Codeforces Round 896 (Div. 2)
// URL: https://codeforces.com/contest/1869/problem/C
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
        ll n, m;
        cin >> n >> m;
        
        ll a[n][m], c = 1;
        
        set<ll> ans;
        set<ll> s;
                
    	for(ll j = 0; j < n; j++){
    		s.insert((c % m));
    		a[j][0] = (c % m);
    		c++;
    		if(c == m) c = 1;
    	}
    	ll x = 0;
    	auto it = s.begin();
    	while(x < s.size() && *it == x){
    		x++;
    		it++;
    	}
    	    	
        ans.insert(x);
        for(ll i = 1; i < m; i++){
        	set<ll> s;
        	for(ll j = 0; j < n; j++){
        		a[j][i] = (a[j][i - 1] + 1)  % m;
        		s.insert(a[j][i]);
        	}
        	ll x = 0;
	    	auto it = s.begin();
	    	while(x < s.size() && *it == x){
	    		x++;
	    		it++;
	    	}
	    	ans.insert(x);
        }
        
        
        x = 0;
    	it = ans.begin();
    	while(x < ans.size() && *it == x){
    		x++;
    		it++;
    	}
    	
    	cout << x << '\n';
        
        for(ll i = 0; i < n; i++){
        	for(ll j = 0; j < m; j++){
        		cout << a[i][j] << ' ';
        	}
        	cout << '\n';
        }
        
        
    }
    
    
    return 0;
}