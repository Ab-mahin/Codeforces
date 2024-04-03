// USER: "Ab.Mahin"
// Problem: G. Bicycles
// Contest: Codeforces - Codeforces Round 918 (Div. 4)
// URL: https://codeforces.com/contest/1915/problem/G
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
//#define m 1000000007 // 998244353
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
const ll N = 1e3 + 5;
ll dis[N + 5][N + 5];
vector<pair<ll,ll>> g[N];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    int t, tt;
    t = tt = 1;
    
    cin >> t;
	
    while(t--){
        int n, m;
        cin >> n >> m;
        
        for(int i = 0; i <= n; i++) g[i].clear();
        
        for(int i = 0; i < m; i++){
        	ll u, v, w;
        	cin >> u >> v >> w;
        	g[u].push_back({v, w});
        	g[v].push_back({u, w});
        }
        
        for(int i = 1; i <= N; i++){
        	for(ll j = 1; j <= N; j++){
        		dis[i][j] = MAX;
        	}
        }
        
        ll s[n + 1];
        ll ans = MAX;
        for(int i = 1; i <= n; i++) cin >> s[i];
                
        priority_queue <pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll>>, greater<pair<pair<ll, ll>, ll>>> q;
        
        q.push({{0, N}, 1});
        dis[N][1] = 0;
        while(!q.empty()){
        	ll u = q.top().second;
        	ll c = q.top().first.first;
        	ll mc = q.top().first.second;
        	q.pop();
        	//if (c > dis[mc][u]) continue;
        	for(auto i : g[u]){
        		ll x = i.first;
        		ll y = i.second;
        		ll mn = min(mc, s[u]);
        		if(dis[mn][x] > dis[mc][u] + (mn * y)){
        			dis[mn][x] = dis[mc][u] + (mn * y);
        			q.push({{dis[mn][x], mn}, x});
        		}
        	}
        }
                
        for(ll i = 1; i <= N; i++){
        	ans = min(ans, dis[i][n]);
        }
        cout << ans << '\n';
    }
    
    
    return 0;
}