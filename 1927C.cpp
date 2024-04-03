// USER: "Ab.Mahin"
// Problem: C. Choose the Different Ones!
// Contest: Codeforces - Codeforces Round 923 (Div. 3)
// URL: https://codeforces.com/contest/1927/problem/C
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
        ll n, m, k;
        cin >> n >> m >> k;
        ll a[n], b[m];
        map<ll,ll> mp, pm;
        for(ll i = 0; i < n; i++) {cin >> a[i];if(a[i] <=  k)mp[a[i]]++;}
        for(ll i = 0; i < m; i++) {cin >> b[i]; if(b[i] <=  k)pm[b[i]]++;}
        ll x = (k / 2), y = x;
        ll ok = 1;
        for(ll i = 1; i <= k; i++){
        	if(mp[i] == 0 && pm[i] == 0) {
        		ok = 0;
        		x = 0, y = 1;
        		break;
        	}
        	if(mp[i] && !pm[i]){
        		mp[i] = 0;
        		if(x) x--;
        	}
        	else if(!mp[i] && pm[i]){
        		pm[i] = 0;
        		if(y) y--;
        	}
        }
        
        
        if(ok){
        	for(ll i = 1; i <= k; i++){
        		if(mp[i] && pm[i]){
	        		if(x) x--;
	        		if(y) y--;
	        		continue;
	        	}
        	}
        	
        }
                        
        if(x == y && ok){
        	cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
                
    }
    
    
    return 0;
}