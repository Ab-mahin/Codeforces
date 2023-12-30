// USER: "Ab.Mahin"
// Problem: H. Mad City
// Contest: Codeforces - Codeforces Round 898 (Div. 4)
// URL: https://codeforces.com/contest/1873/problem/H
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
vector<ll> g[N];
ll vis[N], ok = 0, s, lev[N], dis[N];

void bfs(ll v, ll ck){
	queue<ll> q;
	q.push(v);
	if(ck == 2) dis[v] = 0;
	else lev[v] = 0;
	while(!q.empty()){
		ll p = q.front();
		q.pop();
		for(auto i : g[p]){
			if(ck == 2){
				if(dis[p] + 1 < dis[i]){
					dis[i] = dis[p] + 1;
					q.push(i);
				}
			}
			else {
				if(lev[p] + 1 < lev[i]){
					lev[i] = lev[p] + 1;
					q.push(i);
				}
			}
		}
		
	}
}

void dfs(ll u, ll p, ll ck){
	vis[u] = ck;
	for(auto v : g[u]){
		if(v != p){
			if(vis[v] == ck){
				ok |= (lev[v] < dis[v]);
			}
			if(vis[v] != ck){
				dfs(v, u, ck);
			}
		}
	}
	
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
        ll n, a, b;
        cin >> n >> a >> b;
        
        for(ll i = 0; i <= n; i++){
        	g[i].clear();
        	vis[i] = 0;
        	lev[i] = dis[i] = INT_MAX;
        }
        
        
        for(ll i = 0; i < n; i++){
        	ll u, v;
        	cin >> u >> v;
        	g[u].push_back(v);
        	g[v].push_back(u);
        }
        
        ok = 0;
        bfs(a, 2);
        bfs(b, 3);
        dfs(b, 0, 1);
        
       
        cout << (ok ? "YES" : "NO") << '\n';
                
    }
    
    
    return 0;
}