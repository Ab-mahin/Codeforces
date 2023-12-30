// USER: "Ab.Mahin"
// Problem: C. Colorful Table
// Contest: Codeforces - CodeTON Round 6 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1870/problem/C
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
        ll ans[k + 1]{0};
        vector<ll> a(n), v[k + 1];
        
        ordered_set<ll> s;
        
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        	v[a[i]].push_back(i);
        	s.insert(i);
        }
        
        sort(a.begin(), a.end());
        
        for(ll i = 0; i < n; i++){
        	ll x = *s.begin();
        	ll y = *s.rbegin();
        	ans[a[i]] = max(ans[a[i]], (y - x + 1) * 2);
        	for(ll j = 0; j < v[a[i]].size(); j++){
        		ll d = v[a[i]][j];
        		s.erase(s.upper_bound(d));
        	}
        	if(v[a[i]].size()) v[a[i]].clear();
        }
        
        for(ll i = 1; i <= k; i++){
        	cout << ans[i] << " \n"[i == k];
        }
        
    }
    
    
    return 0;
}