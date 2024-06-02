// USER: "Ab.Mahin"
// Problem: D. Colored Balls
// Contest: Codeforces - Educational Codeforces Round 164 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1954/problem/D
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define m 998244353

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
const ll N = 5e3 + 5;
ll a[N], n, dp[N];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
	
    while(t--){
        cin >> n;
        
        ll cnt = 0, ans = 0;
        for(ll i = 0; i < n; i++) cin >> a[i], cnt += a[i];
        sort(a, a + n);
        dp[0] = 1;
        for(ll i = 0; i < n; i++){
        	for(ll j = 0; j <= cnt; j++){
        		if(j <= a[i]){
        			ans = (ans + (a[i] * dp[j])) % m;
        		}
        		else ans = (ans + (((a[i] + 1 + j) / 2) * dp[j]) % m) % m;
        	}
        	for(ll j = cnt; j >= a[i]; j--){
        		dp[j] = (dp[j] + dp[j - a[i]]) % m;
        	}
        }
        cout << (ans + m) % m << '\n';
    }
    
    
    return 0;
}