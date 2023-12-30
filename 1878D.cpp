// USER: "Ab.Mahin"
// Problem: D. Reverse Madness
// Contest: Codeforces - Codeforces Round 900 (Div. 3)
// URL: https://codeforces.com/contest/1878/problem/D
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
        string s;
        cin >> s;
        
        ll l[k], r[k], ans[n + 5]{0}, work[n]{0};
        
        for(ll i = 0; i < k; i++) cin >> l[i],l[i]--;
        for(ll i = 0; i < k; i++) cin >> r[i],r[i]--;
        
        ll q;
        cin >> q;
        vector<ll> v;
        while(q--){
        	ll x;
        	cin >> x;
        	x--;
        	v.push_back(x);
        }
        sort(v.begin(), v.end());
        
        for(ll i = 0, j = 0; i < (ll)v.size(); i++){
        	while(r[j] < v[i]){
        		j++;
        	}
        	
        	ll x = min(v[i], l[j] + r[j] - v[i]);
        	ll y = max(v[i], l[j] + r[j] - v[i]);
        	ans[x]++;
        	ans[y + 1]--;
        }
        
        for(ll i = 0; i < k; i++){
        	for(ll j = l[i]; j <= r[i]; j++){
        		if(j != 0){
        			ans[j] += ans[j - 1];
        		}
        		ll x = min(j, l[i] + r[i] - j);
        		ll y = max(j, l[i] + r[i] - j);
        		work[x] = y;
        		work[y] = x;
        	}
        }
        
        for(ll i = 0; i < n; i++){
        	if(ans[i] & 1){
        		swap(s[work[i]], s[i]);
        		ans[work[i]]--;
        	}
        }
        cout << s << '\n';        
    }
    
    
    return 0;
}