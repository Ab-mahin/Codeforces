// USER: "Ab.Mahin"
// Problem: E. Riding in a Lift
// Contest: Codeforces - Codeforces Round 274 (Div. 2)
// URL: https://codeforces.com/contest/479/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll int
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
const ll N = 5000;
ll dp[N + 5][N + 5];
long long csum[N + 5][2];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll t, tt;
    t = tt = 1;
      
    //cin >> t;
	
    while(t--){
        ll n, a, b, k;
        cin >> n >> a >> b >> k;
                
        for(ll i = 1; i <= k; i++){
        	for(ll j = 1; j <= n; j++){
        		ll mx =  max(0, abs(b - j) - 1);
        		if(i == 1){
        			dp[j][i] = mx;
					if(j >= b){
						dp[j][i] = (dp[j][i] + min(n - j, mx)) % m;
					}
					else{
						dp[j][i] = (dp[j][i] + min(j - 1, mx)) % m;
					}
					csum[j][i & 1] = dp[j][i] % m;
        		}
        		else{
        			
        			ll x = 0, y = 0;
        			
        			if(j >= b){
        				x = b + 1;
        				y = min(n, j + mx);
        			}
        			else x = max(j - mx, 1), y = b - 1;
        			        			
        			dp[j][i] = (dp[j][i] + m + m + csum[y][!(i & 1)] - csum[x - 1][!(i & 1)] - dp[j][i - 1]) % m;
					
					csum[j][i & 1] = dp[j][i] % m;
        		}
        		csum[j][i & 1] = (csum[j][i & 1] + csum[j - 1][i & 1]) % m;
        	}
        }
        
        cout << dp[a][k] << '\n';
        
    }
    
    
    return 0;
}