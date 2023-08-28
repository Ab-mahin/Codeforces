// USER: "Ab.Mahin"
// Problem: C. Another Array Problem
// Contest: Codeforces - Codeforces Round 840 (Div. 2) and Enigma 2022 - Cybros LNMIIT
// URL: https://codeforces.com/contest/1763/problem/C
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
#define m 1000000007


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

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        
        ll a[n],mx = 0;
        for(ll i = 0; i < n; i++){
        	cin >> a[i]; 
        	mx = max(a[i], mx);    	
        }
        
        
        ll ans = 0;
        
        
        
        if(n == 1) ans = a[0];
        else if(n == 2){
        	ans = max((a[0] + a[1]), abs(a[0] - a[1]) * 2);
        }
        else if(n == 3){
        	ans = max({a[0] + a[1] + a[2], a[0] * n, a[n - 1] * n, abs(a[0] - a[1]) * n, abs(a[n - 1] - a[n - 2]) * n, abs(a[0] - a[n - 1]) * n});
        }
        else if(n >= 4) ans = mx * n;
        
        cout << ans << '\n';
        
    }
    
    
    return 0;
}