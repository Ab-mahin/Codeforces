// USER: "Ab.Mahin"
// Problem: D. Almost All Divisors
// Contest: Codeforces - Codeforces Round 560 (Div. 3)
// URL: https://codeforces.com/contest/1165/problem/D
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
const ll N = 1e6 + 5;
ll spf[N];

void solve(){
	for(ll i = 0; i < N; i++) spf[i] = i;
	for(ll i = 2; i < N; i++){
		for(ll j = i; j < N; j += i) spf[j] = min(spf[j], i);
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
	solve();
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        for(ll i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        
        ll ans = a[0] * a[n - 1], d = 0;
        
        for(ll i = 1; i * i <= ans; i++){
        	if(ans % i == 0){
        		if(ans / i != i){
        			d++;
        		}
        		d++;
        	}
        }
        for(ll i = 0, j = n - 1; i <= j; i++, j--){
        	if(a[i] * a[j] != ans){
        		ans = -1;
        		break;
        	}
        }
        if(d - 2 != n) ans = -1;
        cout << ans << '\n';        
    }
    
    
    return 0;
}