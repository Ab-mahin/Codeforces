// USER: "Ab.Mahin"
// Problem: G. GCD on a grid
// Contest: Codeforces - Codeforces Round 938 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1955/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll int
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
const ll N = 101;

ll a[N][N], n, m, d = 0;
ll dp[N][N];
ll solve(ll i, ll j){
	//bug(a[i][j], d);
	if(a[i][j] % d) return 0;
	if(i == n - 1 && j == m - 1) return 1;
	ll &res = dp[i][j];
	if(~res) return res;
	res = 0;
	if(i + 1 < n){
		res = max(res, solve(i + 1, j));
	}
	if(j + 1 < m){
		res = max(res, solve(i, j + 1));
	}
	return res;
}

void ok(){
	for(ll i = 0; i <= n; i++){
		for(ll j = 0; j <= m; j++) dp[i][j] = -1;
	}
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
        cin >> n >> m;
        for(ll i = 0; i < n; i++){
        	for(ll j = 0; j < m; j++){
        		cin >> a[i][j];
        	}
        }
        ll x = a[0][0], ans = 1;
        for(ll i = 1; i * i <= x; i++){
        	if(x % i == 0){
        		ok();
        		d = i;
        		if(solve(0, 0)){
        			ans = max(ans, i);
        		}
        		ll y = x / i;
        		
        		if(y != i){
        			ok();
        			d = y;
        			if(solve(0, 0)) ans = max(ans, y);
        		}
        	}
        }
        
        cout << ans << '\n';
                
    }
    
    
    return 0;
}