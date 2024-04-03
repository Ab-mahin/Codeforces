// USER: "Ab.Mahin"
// Problem: C. Tree Cutting
// Contest: Codeforces - Codeforces Round 936 (Div. 2)
// URL: https://codeforces.com/contest/1946/problem/C
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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


/* To finding all possible submask for a mask(set bits);
 
for(ll mask = 0; mask < (1 << n); mask++){
    for(ll submask = mask ; submask > 0; submask = (submask - 1) & mask){
    	cout << mask << ' ' << submask << '\n';	
    }
}
*/

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
ll m, c;
vector<ll> g[N];

ll dfs(ll u, ll p){
	ll d = 1;
	for(auto v : g[u]){
		if(v != p){
			d += dfs(v, u);
		}
	}
	if(d >= m){
		c++;
		d = 0;
	}
	return d;
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
    
    cin >> t;
	
    while(t--){
        ll n, k;
        cin >> n >> k;
        for(ll i = 0; i <= n; i++) g[i].clear();
        for(ll i = 0; i < n - 1; i++){
        	ll u, v;
        	cin >> u >> v;
        	g[u].push_back(v);
        	g[v].push_back(u);
        }
        
        ll lo = 1, hi = n, ans = 0;
        
        while(lo <= hi){
        	m = (lo + hi) >> 1;
        	c = 0;
        	dfs(1, -1);
        	if(c > k){
        		ans = m, lo = m + 1;
        	}
        	else hi = m - 1;
        }
        cout << ans << '\n';
                
    }
    
    
    return 0;
}