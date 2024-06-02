// USER: "Ab.Mahin"
// Problem: F. Unfair Game
// Contest: Codeforces - Codeforces Round 938 (Div. 3)
// URL: https://codeforces.com/contest/1955/problem/F
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
const ll N = 2e2 + 5;
ll dp[N][N][N];

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
    for(ll i = 0; i < N; i++){
    	for(ll j = 0; j < N; j++){
    		for(ll k = 0; k < N; k++){
    			ll x = 0;
    			x = (i & 1) ? 1 : 0;
    			x ^= (j & 1) ? 2 : 0;
    			x ^= (k & 1) ? 3 : 0;
    			dp[i][j][k] = max({dp[i ? i - 1 : 0][j][k], dp[i][j ? j - 1 : 0][k], dp[i][j][k ? k - 1 : 0]});
    			if(x == 0) dp[i][j][k]++;
    		}
    	}
    }
	
    while(t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
    	cout << dp[a][b][c] + d / 2 - 1 << '\n';
    }
    
    
    return 0;
}