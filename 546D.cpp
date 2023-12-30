// USER: "Ab.Mahin"
// Problem: D. Soldier and Number Game
// Contest: Codeforces - Codeforces Round 304 (Div. 2)
// URL: https://codeforces.com/contest/546/problem/D
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
const ll N = 5e6 + 5;
ll spf[N], val[N];
void fun(){
	for(ll i = 2; i < N; i++) spf[i] = i;
	for(ll i = 2; i < N; i++){
		for(ll j = i; j < N; j += i){
			spf[j] = min(spf[j], i);
		}
	}
	val[1] = 0;
	for(ll i = 2; i < N; i++){
		ll x = i;
		while(!val[x] && x != 1){
			x /= spf[x];
			val[i] = val[x] + 1;
		}
	}
	
	for(ll i = 2; i < N; i++){
		val[i] += val[i - 1];
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
    
	fun();
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll ans = val[a] - val[b];
        cout << ans << '\n';
    }
    
    
    return 0;
}