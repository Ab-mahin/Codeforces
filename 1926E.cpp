// USER: "Ab.Mahin"
// Problem: E. Vlad and an Odd Ordering
// Contest: Codeforces - Codeforces Round 928 (Div. 4)
// URL: https://codeforces.com/contest/1926/problem/E
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
        ll n, k;
        cin >> n >> k;
        
        if((n + 1) / 2 >= k){
        	cout << (k * 2) - 1 << '\n';
        }
        else{
        	ll x = (n + 1) / 2, y = x, ans = 0;
        	for(ll i = 1; (1 << i) <= n; i++){
        		ll lo = 1, hi = x, res = 0;
        		if(x == k) break;
        		while(lo <= hi){
        			ll mid = (lo + hi) / 2;
        			ll d = ((mid * 2) - 1);
        			ll m = (1 << i);
        			if(d * m <= n && x + mid <= k){
        				lo = mid + 1;
        				ans = d * (1 << i);
        				if(x == k) break;
        				res = mid;
        			}
        			else hi = mid - 1;
        		}
        		x += res;
        	}
        	cout << ans << '\n';
        }
                
    }
    
    
    return 0;
}