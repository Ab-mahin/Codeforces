// USER: "Ab.Mahin"
// Problem: G. Shuffling Songs
// Contest: Codeforces - Codeforces Round 937 (Div. 4)
// URL: https://codeforces.com/contest/1950/problem/G
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
const ll N = 16;
ll dp[1 << N][N];
ll ck[N][N];
ll n;
ll solve(ll mask, ll en){
	ll &res = dp[mask][en];
	if(res != -1) return res;
	
	res = 0;
	for(ll i = 0; i < n; i++){
		if(ck[en][i] || !mask){
			if((mask & (1 << i)) == 0) res = max(res, solve(mask | (1 << i), i) + 1);
		}
	}
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
        cin >> n;
        
        string g[n], w[n];
        
        for(ll i = 0; i < n; i++){
        	cin >> g[i] >> w[i];
        }
        memset(ck, 0, sizeof ck);
        for(ll i = 0; i < n; i++){
        	for(ll j = 0; j < n; j++){
        		if(g[i] == g[j] || w[i] == w[j]){
        			ck[i][j] = 1;
        		}
        	}
        }
        
        memset(dp, -1, sizeof dp);
        
        ll ans = 0;
        
        for(ll i = 0; i < n; i++){
        	ll x = solve(i, 0);
        	ans = max(ans, x);
        }
        cout << n - ans << '\n';
                
    }
    
    
    return 0;
}