// USER: "Ab.Mahin"
// Problem: B. Collecting Game
// Contest: Codeforces - Codeforces Round 914 (Div. 2)
// URL: https://codeforces.com/contest/1904/problem/B
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
        
        vector<pair<ll, ll>> v;
        ll a[n + 1], d = 0;
        
        for(ll i = 0;i < n; i++){
        	cin >> a[i];
        	d += a[i];
        	v.push_back({a[i], i});
        }
        a[n] = -1 * d;
        
        sort(v.begin(), v.end());
        sort(a, a + n);
        ll ans[n], res[n];
        memset(ans, -1, sizeof ans);
        memset(res, -1, sizeof res);
        stack<ll> s;
        vector<ll> b;
        ll sum = 0;
        for(ll i = 0;i < n; i++){
        	sum += a[i];
        	b.push_back(a[i]);
        	//cout << sum << ' ' << a[i + 1] << '\n';
        	if(sum >= a[i + 1]){
        		//
        	}
        	else {
        		ll j = i;
        		while(j >= 0 && res[j] == -1){
        			res[j] = b.size() - 1;
        			j--;
        		}
        	}
        }
        ll j = n - 1;
		while(j >= 0 && res[j] == -1){
			res[j] = b.size() - 1;
			j--;
		}
		
		
		if(n >= 2 && (a[0] == a[1])){
			res[0] = res[1];
		}
		
		for(ll i = 0; i < n; i++){
			ans[v[i].second] = res[i];
		}
		for(ll i = 0; i < n; i++){
			cout << ans[i] << " \n"[i == n - 1];
		}
    }
    
    
    return 0;
}