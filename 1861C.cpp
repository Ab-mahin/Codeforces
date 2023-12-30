// USER: "Ab.Mahin"
// Problem: C. Robot in a Hallway
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/C
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
#define MAX LLONG_MAX

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

    ll t, tt;
    t = tt = 1;
    
    cin >> t;
	
    while(t--){
        ll n;
        cin >> n;
        
        vector<ll> clk(n, 0), aclk(n, 0);
        
        ll a[2][n];
        for(ll i = 0; i < 2; i++){
        	for(ll j = 0; j < n; j++){
        		cin >> a[i][j];
        		a[i][j]++;
        	}
        }
        a[0][0] = 0;
        
        clk[n - 1] = max(a[0][n - 1] + 1, a[1][n - 1]);
        aclk[n - 1] = max(a[1][n - 1] + 1, a[0][n - 1]);
        
        ll d = 2;
        for(ll i = n - 2; i >= 0; i--){
        	d += 2;
        	clk[i] = max({a[0][i] + d - 1, a[1][i], clk[i + 1] + 1});
        	aclk[i] = max({a[1][i] + d - 1, a[0][i], aclk[i  + 1] + 1});
        }
        
        ll ans = INT_MAX, curr = -1;
        for(ll i = 0; i < n; i++, d -= 2){
        	if(i & 1){
        		ans = min(ans, max(aclk[i], curr + d));
        		curr = max(curr + 1, a[1][i]);
        		curr = max(curr + 1, a[0][i]);
        	}
        	else {
        		ans = min(ans, max(clk[i], curr + d));
        		curr = max(curr + 1, a[0][i]);
        		curr = max(curr + 1, a[1][i]);
        	}
        }
        cout << ans << '\n';
                
    }
    
    
    return 0;
}