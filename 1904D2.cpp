// USER: "Ab.Mahin"
// Problem: D2. Set To Max (Hard Version)
// Contest: Codeforces - Codeforces Round 914 (Div. 2)
// URL: https://codeforces.com/contest/1904/problem/D2
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
ll x[N], y[N], n;
struct{
	ll mx = 0, mn = MAX;
}tr[4 * N];
  
void build(ll n, ll b, ll e){
	if(b == e){
		tr[n].mx = x[b], tr[n].mn = y[b];
		return;
	}
	ll mid = (b + e) >> 1, l = n << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tr[n].mx = max(tr[l].mx, tr[r].mx);
    tr[n].mn = min(tr[l].mn, tr[r].mn);
}

pair<ll,ll> query(ll n, ll b, ll e, ll i, ll j) {
    if (b > j || e < i) return {0, MAX};
    if (b >= i && e <= j) return {tr[n].mx, tr[n].mn};
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    pair<ll, ll> L = query(l, b, mid, i, j);
    pair<ll, ll> R = query(r, mid + 1, e, i, j);
    return {max(L.first, R.first), min(L.second, R.second)};
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
        cin >> n;
        vector<ll> rv[n + 5], v;
        
        for(ll i = 1; i <= n; i++){
        	cin >> x[i];
        	if(!rv[x[i]].size()){
        		v.push_back(x[i]);
				rv[x[i]].push_back(0);
        	}
			rv[x[i]].push_back(i);
        	
        }
        for(ll i = 1; i <= n; i++){
        	cin >> y[i];
        }
        
        for(ll i = 0; i < v.size(); i++){
			rv[v[i]].push_back(n + 1);
        }
        x[0] = x[n + 1] = 0;
        y[0] = y[n + 1] = n + 1;
        
        build(1, 0, n + 1);
        ll ok = 1;
        
        for(ll i = 1; i <= n; i++){
        	if(x[i] > y[i] || !ok){
        		ok = 0;
        		break;
        	}
        	if(x[i] == y[i]) continue;
        	
        	ll ck = 0;
        	
        	ll j = lower_bound(rv[y[i]].begin(), rv[y[i]].end(), i) - rv[y[i]].begin();
        	if(j <  rv[y[i]].size()){
        		ll p = rv[y[i]][j];
        		pair<ll, ll> q = query(1, 0, n + 1, i, p);
        		if(q.first == y[i] && q.second >= y[i]){
        			ck = 1;
        		}
        		p = rv[y[i]][j - 1];
        		q = query(1, 0, n + 1, p, i);
        		if(q.first == y[i] && q.second >= y[i]){
        			ck = 1;
        		}
        	}
        	
        	ok &= ck;
        	
        }
        
        cout << (ok ? "YES" : "NO") << '\n';
    }
    
    
    return 0;
}