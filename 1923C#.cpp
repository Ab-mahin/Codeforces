// USER: "Ab.Mahin"
// Problem: C. Find B
// Contest: Codeforces - Educational Codeforces Round 162 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1923/problem/C#
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
    
    cin >> t;
	
    while(t--){
        ll n, q;
        cin >> n >> q;
        
        ll a[n + 1], cnt[n + 1]{0}, sum[n + 1]{0};
        
        for(ll  i = 1; i <= n; i++){
        	cin >> a[i];
        	sum[i] = sum[i - 1] + a[i];
        	cnt[i] = (a[i] == 1); 
        }
        
        for(ll i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
        
        while(q--){
        	ll l, r;
        	cin >> l >> r;
        	
        	ll x = cnt[r] - cnt[l - 1];
        	ll val = (sum[r] - sum[l - 1]);
        	
        	ll ok = 1;
        	if(x * 2 + (r - l + 1 - x) > val || l == r) ok = 0;
        	
        	//cout << x * 2 << ' ' << (r - l + 1 - x) << ' ' << val << '\n';
        	
        	cout << (ok ? "YES" : "NO") << '\n';
        }
        
    }
    
    
    return 0;
}