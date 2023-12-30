// USER: "Ab.Mahin"
// Problem: F. A Growing Tree
// Contest: Codeforces - Codeforces Round 907 (Div. 2)
// URL: https://codeforces.com/contest/1891/problem/F
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
#define lc (n << 1)
#define rc ((n << 1) | 1)


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
const ll N = 5e5 + 5;
ll st[N], en[N], ti = 0, ans[N];
bitset<N> vis;
vector<ll> g[N];
void dfs(ll u){
	vis[u] = 1;
	st[u] = ti++;
	for(auto i : g[u]){
		if(!vis[i]){
			dfs(i);
		}
	}
	en[u] = ti - 1;
}

struct{
	ll sum, lazy;
}tr[4 * N];


void push(ll n, ll b, ll e){
	if (tr[n].lazy == 0) return;
    tr[n].sum = tr[n].sum + tr[n].lazy * (e - b + 1);
    if (b != e) {
       tr[lc].lazy = tr[lc].lazy + tr[n].lazy;
       tr[rc].lazy = tr[rc].lazy + tr[n].lazy;
    }
    tr[n].lazy = 0;
}

void pull(ll n){
	tr[n].sum = tr[lc].sum + tr[rc].sum;
}

ll combine(ll a, ll b){
	return a + b;
}

void build(ll n, ll b, ll e){
	tr[n].lazy = 0;
	if(b == e){
		tr[n].sum = 0;
		return;
	}
	ll mid = (b + e) >> 1;
	build(lc, b, mid);
	build(rc, mid + 1, e);
	pull(n);
}

void upd(ll n, ll b, ll e, ll l, ll r, ll v){
	push(n, b, e);
	if (r < b || e < l) return;
	if(l <= b && e <= r){
	   tr[n].lazy = v;
       push(n, b, e);
       return;
	}
	ll mid = (b + e) >> 1;
	upd(lc, b, mid, l, r, v);
	upd(rc, mid + 1, e, l, r, v);
	pull(n);
}

ll query(ll n, ll b, ll e, ll l, ll r){
	push(n, b, e);
    if (l > e || b > r) return 0;
    if (l <= b && e <= r) return tr[n].sum;
    ll mid = (b + e) >> 1;
    return combine(query(lc, b, mid, l, r), query(rc, mid + 1, e, l, r));
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
	ll n = 1;
    while(t--){
        ll q;
        cin >> q;
        ll c = 2;
        vector<vector<ll>> p; 
        
        for(ll i = 0; i <= n; i++){
        	vis[i] = false;
        	st[i] = en[i] = 0;
        	g[i].clear();
        }
        while(q--){
        	ll op;
        	cin >> op;
        	vector<ll> nxt;
        	nxt.push_back(op);
        	if(op & 1){
        		ll v;
        		cin >> v;
        		g[v].push_back(c);
        		nxt.push_back(c);
        		c++;
        	}
        	else {
        		ll i, v;
        		cin >> i >> v;
        		nxt.push_back(i);
        		nxt.push_back(v);
        	}
        	p.push_back(nxt);
        }
        ti = 0;
        dfs(1);
        build(1, 0, en[1]);
        for(auto i : p){
        	vector<ll> x = i;
        	if(x[0] == 1){
        		ll y =  x[1];
        		ll val = query(1, 0, en[1], st[y], st[y]);
        		upd(1, 0, en[1], st[y], st[y], -val);
        	}
        	else{
        		ll y = x[1];
        		upd(1, 0, en[1], st[y], en[y], x[2]);
        	}
        }
        
        for(ll i = 1; i < c; i++){
        	cout << query(1, 0, en[1], st[i], st[i]) << ' ';
        }
        
        cout << '\n';
        n = c;
    }
    
    
    return 0;
}