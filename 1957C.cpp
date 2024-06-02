// USER: "Ab.Mahin"
// Problem: C. How Does the Rook Move?
// Contest: Codeforces - Codeforces Round 940 (Div. 2) and CodeCraft-23
// URL: https://codeforces.com/contest/1957/problem/C
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
#define m 1000000007 // 998244353
//0x3f

#define MAX LLONG_MAX

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const ll N = 3e5 + 5;
ll dp[N];

ll solve(ll i){
	if(i < 0) return 0;
	if(i <= 1) return 1;
	ll &res = dp[i];
	if(~res) return res;
	res = 0;
	res = solve(i - 1) % m ;
	res = (res + 2 * (i - 1) % m * solve(i - 2) % m);
	res %= m;
	return res;
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
    	
    while(t--){
        ll n, k;
        cin >> n >> k;
	    for(ll i = 1; i < n + 5; i++){
	    	dp[i] = -1;
	    }
        for(ll i = 0; i < k; i++){
        	ll x, y;
        	cin >> x >> y;
        	if(x == y) n--;
        	else n -= 2;
        }
    	cout << solve(n) << '\n';
    }
    
    
    return 0;
}