// USER: "Ab.Mahin"
// Problem: B. Begginer's Zelda
// Contest: Codeforces - Codeforces Round 915 (Div. 2)
// URL: https://codeforces.com/contest/1905/problem/B
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
//#define m 1000000007 // 998244353
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
const ll N = 2e5 + 5;
vector<ll> g[N];
ll vis[N], lev[N];

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
        
        for(ll i = 0; i <= n; i++){
        	g[i].clear();
        	vis[i] = lev[i] = 0;
        }
        
        ll mx = 0, s = 1;
        for(ll i = 0; i < n - 1; i++){
        	ll u, v;
        	cin >> u >> v;
        	g[u].push_back(v);
        	g[v].push_back(u);
        	if(g[u].size() > mx){
        		mx = g[u].size();
        		s = u;
        	} 
        	if(g[v].size() > mx){
        		mx = g[v].size();
        		s = v;
        	}        	
        }
        
        auto dfs = [&](ll u, auto &&dfs)-> ll{
        	vis[u] = 1;
        	ll ck = 1;
        	for(auto v : g[u]){
        		if(!vis[v]){
        			ck = 0;
        			lev[v] += dfs(v, dfs);
        			lev[u] += lev[v];
        		}
        	}
        	return ck;
        };
        
        dfs(s, dfs);
        mx = 0;
        for(ll i = 1; i <= n; i++){
        	mx = max(mx, lev[i]);
        }
        ll ans = (mx + 1) / 2;
        cout << ans << '\n';
        
        
                
    }
    
    
    return 0;
}