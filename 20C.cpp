// USER: "Ab.Mahin"
// Problem: C. Dijkstra?
// Contest: Codeforces - Codeforces Alpha Round 20 (Codeforces format)
// URL: https://codeforces.com/problemset/problem/20/C
// Memory Limit: 64 MB
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
    
    //cin >> t;
	
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<pair<ll,ll>> g[n + 1];
        
        for(ll i = 0; i < m; i++){
        	ll u, v, w;
        	cin >> u >> v >> w;
        	g[u].push_back({v, w});
        	g[v].push_back({u, w});
        }
        
        vector<ll> cost(n + 1, MAX), path(n + 1);
        
        priority_queue<pair<ll, ll> , vector<pair<ll, ll>> , greater<pair<ll,ll>> > q;
        
        cost[0] = cost[1] = 0;

		q.push({0, 1});
		
		while(!q.empty()){
			pair<ll, ll> p = q.top();
			ll w = p.first;
			ll u = p.second;
			q.pop();
			
			if(w > cost[u]) continue;
			for(auto v : g[u]){
				ll a = v.first;
				ll b = v.second;
				if(cost[a] > cost[u] + b){
					cost[a] = cost[u] + b;
					path[a] = u;
					q.push({cost[a], a});
				}
				
			}
		}
		
		if(cost[n] >= MAX){
			cout << -1 << '\n';
		}
		else{
			ll x = n;
			vector<ll> ans;
			ans.push_back(n);
			while(x != 1){
				x = path[x];
				ans.push_back(x);
			}
			for(ll i = ans.size() - 1; i >= 0; i--){
				cout << ans[i] << ' ';
			}
		}
                
    }
    
    
    return 0;
}