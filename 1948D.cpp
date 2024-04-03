// USER: "Ab.Mahin"
// Problem: D. Tandem Repeats?
// Contest: Codeforces - Educational Codeforces Round 163 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1948/problem/D
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
const ll N = 5e3 + 5;
ll dp[N][N];
string s;
ll p;

ll solve(ll i, ll j){
	if(i == p) return 1;
	if(dp[i][i + j] != -1) return dp[i][i + j];
	if(s[i] == s[i + j] || s[i] == '?' || s[i + j] == '?'){
		return dp[i][i + j] = solve(i + 1, j);
	}
	else return dp[i][i + j] = 0;
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
        ll n;
        cin >> s;
        n = s.size();
        for(ll i = 0; i <= n; i++){
        	for(ll j = 0; j <= n; j++){
        		dp[i][j] = -1;
        	}
        }
        ll ans = 0;
        for(ll i = 0; i < n; i++){
        	for(ll j = i + 1; j < n; j += 2){
        		p = i + (j - i + 1) / 2;
        		if(solve(i, (j - i + 1) / 2)){
        			ans = max(ans, j - i + 1);
        		}
        	}
        }
        cout << ans << '\n';       
    }
    
    
    return 0;
}