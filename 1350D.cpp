// USER: "Ab.Mahin"
// Problem: D. Orac and Medians
// Contest: Codeforces - Codeforces Round 641 (Div. 2)
// URL: https://codeforces.com/contest/1350/problem/D
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
        ll a[n], ck = 0;
        
        for(ll i = 0; i < n; i++){
        	cin >> a[i];
        	if(a[i] == k) a[i] = 1, ck = 1;
        	else if(a[i] > k) a[i] = 2;
        	else a[i] = 0;
        }
        
        ll ok = (ck && n == 1);
        for(ll i = 0; i < n; i++){
        	for(ll j = i + 1; j < n && j - i <= 2; j++){
        		if(a[i] && a[j]) ok = ck;
        	}
        }        
        cout << (ok ? "yes" : "no") << '\n';     
    }
    
    
    return 0;
}