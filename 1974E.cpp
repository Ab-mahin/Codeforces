// USER: "Ab.Mahin"
// Problem: E. Money Buys Happiness
// Contest: Codeforces - Codeforces Round 946 (Div. 3)
// URL: https://codeforces.com/contest/1974/problem/E
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
const ll N = 2e5 + 5;
ll dp[51][50*1001], mem[51][50*1001];
ll a[51], c[51], n, x;
ll solve(ll pos, ll happy, ll cost){
	if(pos == n - 1) return (cost >= a[pos] ? c[pos] : 0);
	ll &res = dp[pos][happy];
	if(~res && mem[pos][happy] >= cost) return res;
	res = 0;
	res = solve(pos + 1, happy, cost + x);
	if(cost >= a[pos]) res = max(res, solve(pos + 1, happy + c[pos], cost - a[pos] + x) + c[pos]);
	mem[pos][happy] = cost;
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
        cin >> n >> x;
        ll sum = 0;
        for(ll i = 0; i < n; i++){
        	cin >> a[i] >> c[i];
        	sum += c[i];
        }
        
        for(ll i = 0; i <= n; i++){
        	for(ll j = 0; j <= sum; j++){
        		dp[i][j] = -1;
        		mem[i][j] = 0;
        	}
        }
        
        ll ans = solve(0, 0, 0);
        /*ll ans = 0;     
    	dp[0][0] = 0;
        
        for(ll i = 1; i <= n; i++){
        	for(ll j = 0; j <= sum; j++){
        		if(dp[i - 1][j] == MAX) continue;
        		ll rem = ((i - 1) * x) - dp[i - 1][j];
        		dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        		if(rem >= a[i - 1]){
        			dp[i][j + c[i - 1]] = min(dp[i][j + c[i - 1]], dp[i - 1][j] + a[i - 1]);
        		} 
        	}
        }
        
        for(ll i = 0; i <= sum; i++){
        	if(dp[n][i] <	 MAX){
        		ans = max(ans, i);
        	}
        }*/
        
        cout << ans << '\n';
    }
    
    
    return 0;
}