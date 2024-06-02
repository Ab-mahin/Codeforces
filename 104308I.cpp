// USER: "Ab.Mahin"
// Problem: I. Colorful Queries
// Contest: Codeforces - Mirror of Independence Day Programming Contest 2023 by MIST Computer Club
// URL: https://codeforces.com/gym/104308/problem/I
// Memory Limit: 512 MB
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
//0x3f

#define MAX LLONG_MAX

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//find_by_order() and order_of_key()
//k-th largest element and strictly smaller


/* To finding all possible submask for a mask(set bits);
 
for(ll mask = 0; mask < (1 << n); mask++){
    for(ll submask = mask ; submask > 0; submask = (submask - 1) & mask){
    	cout << mask << ' ' << submask << '\n';	
    }
}
*/

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
const ll N = 1e5 + 5;

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
        ll idx[n + 1]{0}, a[n];
        for(ll i = 1; i <= n; i++){
        	cin >> a[i];
        	if(!idx[a[i]]) idx[a[i]] = i;
        }
        
        ordered_set<ll> os;
        
        ll m = -(q + 1);
        
        for(ll i = 1; i <= n; i++){
        	os.insert(i);
        }
        
        for(ll i = 1; i <= q; i++){
        	ll d;
        	cin >> d;
        	ll ans = os.order_of_key(idx[d] + 1);
        	cout << ans << '\n';
        	os.erase(os.upper_bound(idx[d]));
        	idx[d] = m--;
        	os.insert(idx[d]);
        }
        
    }
    
    
    return 0;
}