// USER: "Ab.Mahin"
// Problem: E. Rudolf and k Bridges
// Contest: Codeforces - Codeforces Round 933 (Div. 3)
// URL: https://codeforces.com/contest/1941/problem/E
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
        ll n, m, k, d;
        cin >> n >> m >> k >> d;
        ll ans[n + 1]{0};
        d++;
        ll a[n][m];
        for(ll i = 0; i < n; ++i){
        	for(ll j = 0; j < m; ++j){
        		cin >> a[i][j];
        		a[i][j]++;
        	}
        	ll c[m]{0};
        	set<pair<ll, ll>> s;
        	s.insert({a[i][0], 0});
        	c[0] = 1;
        	for(ll j = 1; j < m; j++){
        		if(s.size() > d){
        			s.erase(s.find({c[j - d - 1], j - d - 1}));
        		}
        		auto p = *s.begin();
        		ll x = p.first;
        		ll y = p.second;
        		c[j] = x + a[i][j];
        		s.insert({c[j], j});
        	}
        	ans[i + 1] = c[m - 1];
        }
        ll res = MAX;
        
        for(ll i = 1; i <= n; i++){
        	ans[i] += ans[i - 1];
        }
        for(ll i = k; i <= n; i++){
        	res = min(res, ans[i] - ans[i - k]);
        }
        cout << res << '\n';
                
    }
    
    
    return 0;
}